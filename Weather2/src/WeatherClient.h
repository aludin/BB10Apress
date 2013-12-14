/*
 * WeatherClient.h
 *
 *  Created on: Dec 10, 2013
 *      Author: aludin
 */

#ifndef WEATHERCLIENT_H_
#define WEATHERCLIENT_H_

#include <QObject>

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include  "CityInfo.h"
#include "GoogleMapClient.h"



class WeatherClient : public QObject {
	Q_OBJECT
	Q_PROPERTY(CityInfo* cityinfo READ city CONSTANT)
	Q_PROPERTY(GoogleMapClient* mapclient READ googleMapClient CONSTANT)
	public:
	WeatherClient(QObject* parent=0);
	virtual ~WeatherClient();

	void setNetworkManager(QNetworkAccessManager* manager);

signals:
	void multipleCitiesFound(QStringList cities);
	void error(QString message);
	void finished();


public slots:
	void cityWeather(QString city);
	void cityWeather(int selectedIndex);
	void cancel();

private slots:
	void onCityRequestFinished();
	void onWeatherIconRequestFinished();

private:
	CityInfo* city() const;
	GoogleMapClient* googleMapClient();

	void updateCityInfo(const QVariantMap& map);
	void getWeatherIcon(const QString& iconUrl);

	QString m_apiKey;
	QNetworkAccessManager* m_networkManager;
	QList<QNetworkReply*> m_networkReplies;
	CityInfo* m_cityInfo;
	GoogleMapClient* m_googleMapClient;
	QStringList m_cities;

	static const char* m_apiKeyPath;
	static const char* m_keyTag;
	static const char* m_resultsTag;
	static const char* m_responseTag;
	static const char* m_errorTag;
	static const char* m_descriptionTag;
	static const char* m_nameTag;
	static const char* m_cityTag;
	static const char* m_stateTag;
	static const char* m_stateNameTag;
	static const char* m_latitudeTag;
	static const char* m_longitudeTag;
	static const char* m_weatherTag;
	static const char* m_temperatureTag;
	static const char* m_displayLocationTag;
	static const char* m_countryTag;
	static const char* m_countryNameTag;
	static const char* m_USATag;
	static const char* m_currentObservationTag;
	static const char* m_observationTimeTag;
	static const char* m_iconUrlTag;
};

#endif /* WEATHERCLIENT_H_ */
