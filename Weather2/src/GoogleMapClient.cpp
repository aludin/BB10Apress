/*
 * GoogleMapClient.cpp
 *
 *  Created on: Dec 11, 2013
 *      Author: aludin
 */

#include "GoogleMapClient.h"
using namespace bb::cascades;

GoogleMapClient::GoogleMapClient(QObject* parent) :
		QObject(parent), m_networkManager(new QNetworkAccessManager(this)) {

}

GoogleMapClient::~GoogleMapClient() {

}

void GoogleMapClient::setLatitude(const QString& latitude){
	if(m_latitude == latitude) return;
	m_latitude = latitude;
	emit latitudeChanged();
}

QString GoogleMapClient::latitude() const{
	return m_latitude;
}

void GoogleMapClient::setLongitude(const QString& longitude){
	if(m_longitude == longitude) return;
	m_longitude = longitude;
	emit longitudeChanged();
}
QString GoogleMapClient::longitude() const{
	return m_longitude;
}

void GoogleMapClient::setMarkerUrl(const QString& markerUrl){
	if(m_markerUrl == markerUrl) return;
	m_markerUrl = markerUrl;
	emit markerUrlChanged();
}

QString GoogleMapClient::markerUrl() const{
	return m_markerUrl;
}

void GoogleMapClient::loadMap(){

}



QVariant GoogleMapClient::map(){

}

