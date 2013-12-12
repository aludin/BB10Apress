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



class WeatherClient : public QObject {
	Q_OBJECT
	Q_PROPERTY(CityInfo* cityinfo READ city CONSTANT)
public:
	WeatherClient(QObject* parent=0);
	virtual ~WeatherClient();

signals:
	void multipleCitiesFound(QStringList cities);


public slots:
	void cityWeather(QString city);
	void cancel();

private slots:
	void onCityRequestFinished();
	void onWeatherIconRequestFinished();

private:
	CityInfo* city() const;
	void updateCityInfo(const QVariantMap& map);
	void getWeatherIcon();

	QString m_apiKey;
	QNetworkAccessManager* m_networkManager;
	QList<QNetworkReply*> m_networkReplies;
	CityInfo* m_cityInfo;
	QStringList m_cities;

	static const char* m_cityKey;
	static const char* m_stateKey;
	static const char* m_currentObservationKey;
	static const char* m_latitudeKey;
	static const char* m_longitudeKey;

	static const char* m_LocationKey;
	static const char* m_countryKey;


};

#endif /* WEATHERCLIENT_H_ */
