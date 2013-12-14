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
	Q_PROPERTY(QString markerUrl READ markerUrl WRITE setMarkerUrl NOTIFY markerUrlChanged)
	//Q_PROPERTY(QString zoomfactor READ zoomfactor WRITE setZoomFactor NOTIFY zoomFactorChanged)
	Q_PROPERTY(QVariant image READ image NOTIFY imageChanged)

public:
	GoogleMapClient(QObject* parent=0);
	virtual ~GoogleMapClient();



	QString markerUrl() const;

	//void setZoomFactor(QString zoomFactor);
	//QString zoomFactor() const;

	QVariant image();


signals:
	void markerUrlChanged();
	void imageChanged();
public slots:
	void createMap();
	void onCoordinatesChanged(const QString& latitude, const QString& longitude);
	void setMarkerUrl(const QString& markerUrl);
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
