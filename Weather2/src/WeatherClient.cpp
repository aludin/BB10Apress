/*
 * WeatherClient.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: aludin
 */

#include "WeatherClient.h"

#include <QNetworkRequest>
#include <QByteArray>
#include <bb/cascades/QmlDocument>
#include <bb/data/JsonDataAccess>
#include <bb/ImageData>
#include <bb/system/SystemCredentialsPrompt>

using namespace bb::cascades;
using namespace bb::data;
using namespace bb::system;


const char* WeatherClient::m_apiKeyPath =
		"/app/native/assets/apikey/wunderground.json";
const char* WeatherClient::m_keyTag = "key";
const char* WeatherClient::m_resultsTag = "results";
const char* WeatherClient::m_responseTag = "response";
const char* WeatherClient::m_errorTag = "error";
const char* WeatherClient::m_nameTag = "name";
const char* WeatherClient::m_descriptionTag = "description";
const char* WeatherClient::m_cityTag = "city";
const char* WeatherClient::m_stateTag = "state";
const char* WeatherClient::m_stateNameTag = "state_name";
const char* WeatherClient::m_latitudeTag = "latitude";
const char* WeatherClient::m_longitudeTag = "longitude";
const char* WeatherClient::m_weatherTag = "weather";
const char* WeatherClient::m_temperatureTag = "temperature_string";
const char* WeatherClient::m_displayLocationTag = "display_location";
const char* WeatherClient::m_countryTag = "country";
const char* WeatherClient::m_countryNameTag = "country_name";
const char* WeatherClient::m_USATag = "US";
const char* WeatherClient::m_currentObservationTag = "current_observation";
const char* WeatherClient::m_observationTimeTag = "observation_time";
const char* WeatherClient::m_iconUrlTag = "icon_url";

WeatherClient::WeatherClient(QObject* parent) :
		QObject(parent), m_networkManager(
				QmlDocument::defaultDeclarativeEngine()->networkAccessManager()), m_cityInfo(
				new CityInfo(this)) {
	JsonDataAccess jda;
	QVariant keyMap = jda.load(
			QDir::currentPath() + WeatherClient::m_apiKeyPath);

	if (jda.hasError()) {
		emit keyError("Could not read API key!");
	} else {
		m_apiKey = keyMap.toMap()[WeatherClient::m_keyTag].toString();
	}

}


WeatherClient::~WeatherClient() {
}

CityInfo* WeatherClient::city() const {
	return m_cityInfo;
}

void WeatherClient::updateCityInfo(const QVariantMap& data) {
	QVariantMap currentObservation =
			data[WeatherClient::m_currentObservationTag].toMap();
	m_cityInfo->setCity(
			currentObservation[WeatherClient::m_displayLocationTag].toMap()[WeatherClient::m_cityTag].toString());

	m_cityInfo->setState(
			currentObservation[WeatherClient::m_displayLocationTag].toMap()[WeatherClient::m_stateNameTag].toString());

	m_cityInfo->setWeather(
			currentObservation[WeatherClient::m_weatherTag].toString());

	m_cityInfo->setTemperature(
			currentObservation[WeatherClient::m_temperatureTag].toString());

	m_cityInfo->setCoordinates(
			currentObservation[WeatherClient::m_displayLocationTag].toMap()[WeatherClient::m_latitudeTag].toString(),
			currentObservation[WeatherClient::m_displayLocationTag].toMap()[WeatherClient::m_longitudeTag].toString(),
			currentObservation[WeatherClient::m_iconUrlTag].toString());
	m_cityInfo->setLastObservation(
			currentObservation[WeatherClient::m_observationTimeTag].toString());
}

void WeatherClient::cityWeather(int selectedIndex) {
	QString city = m_cities[selectedIndex];
	cityWeather(city);
}

void WeatherClient::cityWeather(QString city) {
	QString urlString("http://api.wunderground.com/api/");
	urlString.append(WeatherClient::m_apiKey);
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
		if (map.contains(WeatherClient::m_currentObservationTag)) {
			this->updateCityInfo(map);
		} else {
			if (map[WeatherClient::m_responseTag].toMap().contains(
					WeatherClient::m_errorTag)) {
				emit error(
						map[WeatherClient::m_responseTag].toMap()[WeatherClient::m_errorTag].toMap()[WeatherClient::m_descriptionTag].toString());
			} else {
				m_cities.clear();
				QVariantList results =
						map[WeatherClient::m_responseTag].toMap()[WeatherClient::m_resultsTag].toList();
				for (int i = 0; i < results.length(); i++) {
					QVariantMap city = results[i].toMap();
					if (city[WeatherClient::m_countryTag].toString()
							== WeatherClient::m_USATag) {
						m_cities.append(
								city[WeatherClient::m_nameTag].toString() + ", "
										+ city[WeatherClient::m_stateTag].toString());
					} else {
						m_cities.append(
								city[WeatherClient::m_nameTag].toString() + ", "
										+ city[WeatherClient::m_countryNameTag].toString());
					}
				}
				emit multipleCitiesFound(m_cities);
			}
		}
	}
	m_networkReplies.removeOne(reply);
	reply->deleteLater();
	emit finished();
}

void WeatherClient::cancel() {

}

