/*
 * GoogleMapClient.h
 *
 *  Created on: Dec 11, 2013
 *      Author: aludin
 */

#ifndef GOOGLEMAPCLIENT_H_
#define GOOGLEMAPCLIENT_H_

#include <QObject>
#include <QNetworkAccessManager>
#include <bb/cascades/Image>


class GoogleMapClient : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
	Q_PROPERTY(QString longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
	Q_PROPERTY(QString markerUrl READ markerUrl WRITE setMarkerUrl NOTIFY markerUrlChanged)
	Q_PROPERTY(QVariant map READ map NOTIFY mapChanged)
public:
	GoogleMapClient(QObject* parent=0);
	virtual ~GoogleMapClient();

	void setLatitude(const QString& latitude);
	QString latitude() const;

	void setLongitude(const QString& longitude);
	QString longitude() const;

	void setMarkerUrl(const QString& markerUrl);
	QString markerUrl() const;

	QVariant map();


	signals:
	void latitudeChanged();
	void longitudeChanged();
	void markerUrlChanged();
	void mapChanged();
public slots:
	void loadMap();
private:
	QNetworkAccessManager* m_networkManager;
	QString m_latitude;
	QString m_longitude;
	QString m_markerUrl;
	bb::cascades::Image m_weatherIcon;

};

#endif /* GOOGLEMAPCLIENT_H_ */
