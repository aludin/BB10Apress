#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

#include <QFile>
#include <QDir>
#include <QVariant>
#include <QAuthenticator>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QByteArray>

#include <bb/cascades/Button>
#include <bb/cascades/TextField>
#include <bb/cascades/TextArea>
#include <bb/cascades/TextInputProperties>
#include <bb/cascades/ImageView>
#include <bb/cascades/Label>
#include <bb/cascades/TabbedPane>
#include <bb/cascades/Tab>
#include <bb/cascades/ScrollView>

#include <bb/system/SystemPrompt>
#include <bb/system/SystemProgressDialog>
#include <bb/system/SystemListDialog>

#include <bb/data/JsonDataAccess>

using namespace bb::cascades;
using namespace bb::data;
using namespace bb::system;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
		QObject(app) {

	m_networkAccessManager = new QNetworkAccessManager(this);

	JsonDataAccess jda;
	QVariant keyMap = jda.load(QDir::currentPath()
				+ "/app/native/assets/keys/wunderground.json");

	if(jda.hasError()){
		qDebug() << "Could not read key file";
	}else{
		m_key = keyMap.toMap()["key"].toString();
	}

	m_progress = new SystemProgressDialog(this);
	m_progress->setState(SystemUiProgressState::Active);
	m_progress->setTitle("Processing ...");
	SystemUiButton *button = m_progress->cancelButton();
	button->setLabel("Cancel");

	bool result = connect(m_progress,
			SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
			SLOT(onProgressFinished(bb::system::SystemUiResult::Type)));
	Q_ASSERT(result);

	m_citiesDialog = new SystemListDialog(this);
	m_citiesDialog->setTitle("Please refine search...");
	m_citiesDialog->setDismissAutomatically(true);

	result = connect(m_citiesDialog,
			SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
			SLOT(onCitiesDialogFinished(bb::system::SystemUiResult::Type)));

	Q_ASSERT(result);

	m_errorPrompt = new SystemPrompt(this);
	m_errorPrompt->setTitle("There was an error...");

	result = connect(m_errorPrompt,
			SIGNAL(finished(bb::system::SystemUiResult::Type)), this,
			SLOT(onErrorPromptFinished(bb::system::SystemUiResult::Type)));
	Q_ASSERT(result);

	// Create scene document from main.qml asset, the parent is set
	// to ensure the document gets destroyed properly at shut down.
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

	// Create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();

	TextField* location = root->findChild<TextField*>("location");

	result = connect(location->input(),
			SIGNAL(submitted (bb::cascades::AbstractTextControl*)), this,
			SLOT(onGetWeather()));
	Q_ASSERT(result);

	TabbedPane* tabbedPane = static_cast<TabbedPane*>(root);
	result = connect(tabbedPane,
			SIGNAL(activeTabChanged(bb::cascades::Tab *)), this,
			SLOT(onActiveTabChanged(bb::cascades::Tab *)));
	Q_ASSERT(result);


	// Set created root object as the application scene
	app->setScene(root);
	location->setText("Los Angeles, CA");
	this->onGetWeather();
}

void::ApplicationUI::onActiveTabChanged(Tab* activeTab){
	if(activeTab->title() == "Map"){
		qDebug() << "Map tab selected";
		for(int i=0; i < m_networkReplies.size(); i++){
			QNetworkReply* reply = m_networkReplies.at(i);
			QNetworkRequest request = reply->request();
			QUrl url = request.url();
			if(url.host() == QString("maps.googleapis.com") && reply->isRunning()){
				m_progress->show();
			}
		}
	}
}

void ApplicationUI::updateUI(const QVariantMap& data) {
	Application* app = static_cast<Application*>(this->parent());

	QVariantMap obs = data["current_observation"].toMap();

	app->scene()->findChild<Label*>("city")->setText(
			obs["display_location"].toMap()["city"].toString());
	app->scene()->findChild<Label*>("state")->setText(
			obs["display_location"].toMap()["state_name"].toString());
	app->scene()->findChild<Label*>("weather")->setText(
			obs["weather"].toString());
	app->scene()->findChild<Label*>("temperature")->setText(
			obs["temperature_string"].toString());

	app->scene()->findChild<Label*>("latitude")->setText(
			"Latitude: "
					+ obs["display_location"].toMap()["latitude"].toString());
	app->scene()->findChild<Label*>("longitude")->setText(
			"Longitude: "
					+ obs["display_location"].toMap()["longitude"].toString());

	app->scene()->findChild<Label*>("observationtime")->setText(
			obs["observation_time"].toString());

	QNetworkRequest iconRequest;
	QString urlString(
			data["current_observation"].toMap()["icon_url"].toString());
	QUrl url(urlString);
	iconRequest.setUrl(url);
	QNetworkReply* reply = m_networkAccessManager->get(iconRequest);

	bool result = connect(reply, SIGNAL(finished()), this,
			SLOT(onGetWeatherIconFinished()));
	Q_ASSERT(result);
	this->m_networkReplies.append(reply);

	QString cityMapUrl("http://maps.googleapis.com/maps/api/staticmap?center=");
	cityMapUrl.append(obs["display_location"].toMap()["latitude"].toString());
	cityMapUrl.append(",");
	cityMapUrl.append(obs["display_location"].toMap()["longitude"].toString());
	cityMapUrl.append("&");
	cityMapUrl.append("zoom=5&size=640x640&sensor=false&");
	cityMapUrl.append("maptype=hybrid&");

	cityMapUrl.append("markers=");
	cityMapUrl.append("icon:");
	cityMapUrl.append(urlString);
	cityMapUrl.append("|");
	cityMapUrl.append(obs["display_location"].toMap()["latitude"].toString());
	cityMapUrl.append(",");
	cityMapUrl.append(obs["display_location"].toMap()["longitude"].toString());
	cityMapUrl.append("|");
	cityMapUrl.append("scale=2");

	qDebug() << cityMapUrl;


	QNetworkRequest mapRequest;
	mapRequest.setUrl(QUrl(cityMapUrl));

	reply = m_networkAccessManager->get(mapRequest);
	result = connect(reply, SIGNAL(finished()), this,
			SLOT(onGetCityMapFinished()));
	Q_ASSERT(result);
	this->m_networkReplies.append(reply);

}

void ApplicationUI::onGetWeather() {
	QString urlString(
			"http://api.wunderground.com/api/");
	urlString.append(m_key);
	urlString.append("/conditions/q/");

	Application* app = static_cast<Application*>(this->parent());
	TextField* location = app->scene()->findChild<TextField*>("location");

	urlString.append(location->text());
	urlString.append(".json");

	QNetworkRequest request;
	request.setUrl(QUrl(urlString));

	QNetworkReply* reply = this->m_networkAccessManager->get(request);
	bool result = connect(reply, SIGNAL(finished()), this,
			SLOT(onRequestFinished()));
	Q_ASSERT(result);
	this->m_networkReplies.append(reply);
	m_progress->show();
}

void ApplicationUI::onRequestFinished() {
	m_progress->cancel();
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (reply->error()) {
		qDebug() << "onRequestFinished: network error!";
		qDebug() << reply->errorString();
	} else {
		Application* app = static_cast<Application*>(this->parent());
		JsonDataAccess jda;
		QVariant response = jda.load(reply);
		if (jda.hasError()) {
			qDebug() << "onRequestFinished: could not parse json response!";
		} else {
			QVariantMap map = response.toMap();
			if (map.contains("current_observation")) {
				this->updateUI(map);
			} else {
				if (map["response"].toMap().contains("error")) {
					qDebug() << "Error in query";
					m_errorPrompt->setBody(
							map["response"].toMap()["error"].toMap()["description"].toString());

					m_errorPrompt->inputField()->setDefaultText(
							app->scene()->findChild<TextField*>("location")->text());
					m_errorPrompt->show();
				} else {
					qDebug() << "onRequestFinished: multiple Cities";
					m_citiesDialog->clearList();
					m_citiesList = map["response"].toMap()["results"].toList();
					if (m_citiesList.size() > 50) {
						m_errorPrompt->setBody(
								"Too many results, refine search");
						m_errorPrompt->inputField()->setDefaultText(
								app->scene()->findChild<TextField*>("location")->text());
						m_errorPrompt->show();
					} else {
						for (int i = 0; i < m_citiesList.length(); i++) {
							QVariantMap city = m_citiesList[i].toMap();
							if (city["country"].toString() == "US") {
								m_citiesDialog->appendItem(
										city["name"].toString() + ", "
												+ city["state"].toString());
							} else {
								m_citiesDialog->appendItem(
										city["name"].toString() + ", "
												+ city["country_name"].toString());
							}
						}
						m_citiesDialog->show();
					}
				}
			}
		}
	}
	this->m_networkReplies.removeOne(reply);
	// qDebug() << m_networkReplies.size();
	reply->deleteLater();
}

void ApplicationUI::onGetWeatherIconFinished() {
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (reply->error()) {
		qDebug() << "Network Error!";
		qDebug() << reply->errorString();
	} else {
		Application* app = static_cast<Application*>(this->parent());
		QByteArray data = reply->readAll();
		QImage image;
		if (!image.loadFromData(data, "GIF")) {
			qDebug() << "onGetWeatherIconFinished: could not load image!";
		}
		QString imagePath = QDir::currentPath()
				+ "/app/native/assets/weatherimage.png";
		if (!image.save(imagePath, "PNG")) {
			qDebug() << "onGetWeatherIconFinished: could not save image!";
		}
		app->scene()->findChild<ImageView*>("weatherImage")->resetImageSource();
		app->scene()->findChild<ImageView*>("weatherImage")->setImageSource(
				QUrl("file://" + imagePath));
	}
	this->m_networkReplies.removeOne(reply);
	// qDebug() << m_networkReplies.size();
	reply->deleteLater();
}
void ApplicationUI::onGetCityMapFinished() {
	m_progress->cancel();
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (reply->error()) {
		qDebug() << "Error in request";
		qDebug() << reply->errorString();
	} else {
		Application* app = static_cast<Application*>(this->parent());
		QByteArray data = reply->readAll();
		QImage image;
		if (!image.loadFromData(data, "PNG")) {
			qDebug() << "onGetCityMapFinished: could not load image!";
		}
		QString imagePath = QDir::currentPath()
				+ "/app/native/assets/citymap.png";
		if (!image.save(imagePath, "PNG")) {
			qDebug() << "onGetCityMapFinished: could not save image!";
		}

		app->scene()->findChild<ImageView*>("citymap")->resetImageSource();
		app->scene()->findChild<ImageView*>("citymap")->setImageSource(
				QUrl("file://" + imagePath));
	}
	this->m_networkReplies.removeOne(reply);
	// qDebug() << m_networkReplies.size();
	reply->deleteLater();
}

void ApplicationUI::onProgressFinished(SystemUiResult::Type type) {
	switch (type) {
	case SystemUiResult::CancelButtonSelection: {
		// cancel here all downloads.
		for (int i = 0; i < this->m_networkReplies.size(); i++) {
			QNetworkReply* reply = this->m_networkReplies.at(i);
			reply->abort();
		}
		break;
	}
	default:
		break;
	}
}

void ApplicationUI::onErrorPromptFinished(SystemUiResult::Type type) {
	Application* app = static_cast<Application*>(this->parent());
	switch (type) {
	case SystemUiResult::ConfirmButtonSelection: {
		app->scene()->findChild<TextField*>("location")->setText(
				m_errorPrompt->inputFieldTextEntry());
		this->onGetWeather();
		break;
	}
	default:
		break;
	}
}

void ApplicationUI::onCitiesDialogFinished(
		bb::system::SystemUiResult::Type type) {
	switch (type) {
	case SystemUiResult::ConfirmButtonSelection: {
		QList<int> indexList = m_citiesDialog->selectedIndices();
		if (indexList.size() == 1) {
			QVariantMap city = m_citiesList.at(indexList.at(0)).toMap();
			Application* app = static_cast<Application*>(this->parent());
			TextField* location = app->scene()->findChild<TextField*>(
					"location");
			if (city["country"].toString() == "US") {
				location->setText(
						city["name"].toString() + ", "
								+ city["state"].toString());
			} else {
				location->setText(
						city["name"].toString() + ", "
								+ city["country_name"].toString());
			}
			this->onGetWeather();
		}
		break;
	}
	default:
		break;
	}
}

