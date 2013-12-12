/*
 * WeatherClient.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: aludin
 */

#include "WeatherClient.h"

#include <QNetworkRequest>
#include <QByteArray>
#include <bb/data/JsonDataAccess>
#include <bb/ImageData>


using namespace bb::data;

const char* WeatherClient::m_cityKey = "city";
const char* WeatherClient::m_stateKey = "state";

WeatherClient::WeatherClient(QObject* parent) :
		QObject(parent), m_networkManager(new QNetworkAccessManager(this)), m_cityInfo(
				new CityInfo(this)) {
	JsonDataAccess jda;
	QVariant keyMap = jda.load(
			QDir::currentPath()
					+ "/app/native/assets/apikey/wunderground.json");

	if (jda.hasError()) {
		qDebug() << "Could not read key file";
	} else {
		m_apiKey = keyMap.toMap()["key"].toString();
	}
}

WeatherClient::~WeatherClient() {
	// TODO Auto-generated destructor stub
}

CityInfo* WeatherClient::city() const {
	return m_cityInfo;
}

void WeatherClient::getWeatherIcon() {
	QNetworkRequest request;
	request.setUrl(QUrl(m_cityInfo->weatherIconUrl()));

	QNetworkReply* reply = this->m_networkManager->get(request);
	bool result = connect(reply, SIGNAL(finished()), this,
			SLOT(onWeatherIconRequestFinished()));
	Q_ASSERT(result);
	this->m_networkReplies.append(reply);
}

void WeatherClient::onWeatherIconRequestFinished() {
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (reply) {
		if (reply->error() == QNetworkReply::NoError) {
			QByteArray data = reply->readAll();
			QImage image;
			image.loadFromData(data);
			QImage swappedImage = image.rgbSwapped();
			if (swappedImage.format() != QImage::Format_RGB32) {
				swappedImage = swappedImage.convertToFormat(
						QImage::Format_RGB32);
			}
			const bb::ImageData imageData = bb::ImageData::fromPixels(
					swappedImage.bits(), bb::PixelFormat::RGBX,
					swappedImage.width(), swappedImage.height(),
					swappedImage.bytesPerLine());

			m_cityInfo->setWeatherIcon(bb::cascades::Image(imageData));
		}
		reply->deleteLater();
	}

}

void WeatherClient::updateCityInfo(const QVariantMap& data) {
	QVariantMap currentObservation = data["current_observation"].toMap();
	m_cityInfo->setCity(
			currentObservation["display_location"].toMap()["city"].toString());

	m_cityInfo->setState(
			currentObservation["display_location"].toMap()["state_name"].toString());

	m_cityInfo->setWeather(currentObservation["weather"].toString());

	m_cityInfo->setTemperature(
			currentObservation["temperature_string"].toString());

	m_cityInfo->setLatitude(
			"Latitude: "
					+ currentObservation["display_location"].toMap()["latitude"].toString());
	m_cityInfo->setLongitude(
			"Longitude: "
					+ currentObservation["display_location"].toMap()["longitude"].toString());

	m_cityInfo->setLastObservation(
			currentObservation["observation_time"].toString());

	m_cityInfo->setWeatherIconUrl(currentObservation["icon_url"].toString());
	this->getWeatherIcon();

}

void WeatherClient::cityWeather(QString city) {
	QString urlString("http://api.wunderground.com/api/");
	urlString.append(m_apiKey);
	urlString.append("/conditions/q/");

	urlString.append(city);
	urlString.append(".json");

	QNetworkRequest request;
	request.setUrl(QUrl(urlString));

	QNetworkReply* reply = this->m_networkManager->get(request);
	bool result = connect(reply, SIGNAL(finished()), this,
			SLOT(onCityRequestFinished()));
	Q_ASSERT(result);
	this->m_networkReplies.append(reply);
}

void WeatherClient::onCityRequestFinished() {
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (!reply->error()) {
		JsonDataAccess jda;
		QVariant response = jda.load(reply);
		QVariantMap map = response.toMap();
		if (map.contains("current_observation")) {
			this->updateCityInfo(map);
		} else {
			if (map["response"].toMap().contains("error")) {
				qDebug() << "Error in query";
			} else {
				qDebug() << "onRequestFinished: multiple Cities";
				m_cities.clear();
				QVariantList results =
						map["response"].toMap()["results"].toList();
				for (int i = 0; i < results.length(); i++) {
					QVariantMap city = results[i].toMap();
					if (city["country"].toString() == "US") {
						m_cities.append(
								city["name"].toString() + ", "
										+ city["state"].toString());
					} else {
						m_cities.append(
								city["name"].toString() + ", "
										+ city["country_name"].toString());
					}
				}
				emit multipleCitiesFound(m_cities);
			}
		}
	}
	m_networkReplies.removeOne(reply);
	reply->deleteLater();
}

void WeatherClient::cancel() {

}

