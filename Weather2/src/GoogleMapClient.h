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
	Q_PROPERTY(QVariant image READ image NOTIFY mapChanged)

public:
	GoogleMapClient(QObject* parent=0);
	virtual ~GoogleMapClient();

	QVariant image();


signals:
	void mapChanged();
public slots:
	void createMap();
	void setCoordinates(const QString& latitude, const QString& longitude, const QString& markerUrl);
private slots:
	void onMapReady();
private:
	QString buildUrlString();

	QNetworkAccessManager* m_networkManager;
	QString m_latitude;
	QString m_longitude;
	QString m_markerUrl;
	bb::cascades::Image m_image;

};

#endif /* GOOGLEMAPCLIENT_H_ */
