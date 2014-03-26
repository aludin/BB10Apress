/*
 * GoogleMapClient.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: aludin
 */

#include <bb/cascades/QmlDocument>
#include "GoogleMapClient.h"
#include <bb/utility/ImageConverter>

using namespace bb::cascades;
using namespace bb::utility;

GoogleMapClient::GoogleMapClient(QObject* parent) :
		QObject(parent), m_networkManager(
				QmlDocument::defaultDeclarativeEngine()->networkAccessManager()) {
}

GoogleMapClient::~GoogleMapClient() {

}

void GoogleMapClient::setCoordinates(const QString& latitude,
		const QString& longitude, const QString& markerUrl) {
	m_latitude = latitude;
	m_longitude = longitude;
	m_markerUrl = markerUrl;
	this->createMap();
}

void GoogleMapClient::createMap() {
	QNetworkRequest request;
	request.setUrl(QUrl(this->buildUrlString()));
	QNetworkReply* reply = this->m_networkManager->get(request);
	bool result = connect(reply, SIGNAL(finished()), this, SLOT(onMapReady()));
	Q_ASSERT(result);
}

void GoogleMapClient::onMapReady() {
	QNetworkReply* reply = static_cast<QNetworkReply*>(QObject::sender());
	if (reply) {
		if (reply->error() == QNetworkReply::NoError) {
			QByteArray data = reply->readAll();
			m_image = bb::cascades::Image(ImageConverter::decode(data));
			emit mapChanged();
		}
		reply->deleteLater();
	}
}

QString GoogleMapClient::buildUrlString() {
	QString cityMapUrl("http://maps.googleapis.com/maps/api/staticmap?center=");
	cityMapUrl.append(m_latitude);
	cityMapUrl.append(",");
	cityMapUrl.append(m_longitude);
	cityMapUrl.append("&");
	cityMapUrl.append("zoom=6&size=640x640&sensor=false&");
	cityMapUrl.append("maptype=hybrid&");
	cityMapUrl.append("markers=");
	cityMapUrl.append("icon:");
	cityMapUrl.append(m_markerUrl);
	cityMapUrl.append("|");
	cityMapUrl.append(m_latitude);
	cityMapUrl.append(",");
	cityMapUrl.append(m_longitude);
	cityMapUrl.append("|");
	cityMapUrl.append("scale=2");
	return cityMapUrl;
}

QVariant GoogleMapClient::image() {
	return QVariant::fromValue(m_image);
}

