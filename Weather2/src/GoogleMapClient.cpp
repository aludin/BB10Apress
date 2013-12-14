/*
 * GoogleMapClient.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: aludin
 */

#include <bb/cascades/QmlDocument>
#include "GoogleMapClient.h"
using namespace bb::cascades;

GoogleMapClient::GoogleMapClient(QObject* parent) :
		QObject(parent), m_networkManager(QmlDocument::defaultDeclarativeEngine()->networkAccessManager()){
}

GoogleMapClient::~GoogleMapClient() {

}

void GoogleMapClient::onCoordinatesChanged(const QString& latitude, const QString& longitude){
	m_latitude = latitude;
	m_longitude = longitude;
	this->createMap();
	emit imageChanged();
}




void GoogleMapClient::setMarkerUrl(const QString& markerUrl) {
	if (m_markerUrl == markerUrl)
		return;
	m_markerUrl = markerUrl;
	emit markerUrlChanged();
}

QString GoogleMapClient::markerUrl() const {
	return m_markerUrl;
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

			m_image = bb::cascades::Image(imageData);
			emit imageChanged();
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
	cityMapUrl.append("zoom=7&size=640x640&sensor=false&");
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

