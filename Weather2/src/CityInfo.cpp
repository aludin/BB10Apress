/*
 * City.cpp
 *
 *  Created on: Dec 10, 2013
 *      Author: aludin
 */

#include "CityInfo.h"

CityInfo::CityInfo(QObject* parent) :
		QObject(parent) {

}

CityInfo::~CityInfo() {

}

void CityInfo::setCity(const QString& city) {
	if (m_city == city)
		return;
	m_city = city;
	emit cityChanged();

}
QString CityInfo::city() const {
	return m_city;
}

void CityInfo::setState(const QString& state) {
	if (m_state == state)
		return;
	m_state = state;
	emit stateChanged();
}
QString CityInfo::state() const {
	return m_state;
}

void CityInfo::setCoordinates(const QString& latitude,
		const QString& longitude) {
	if ((m_latitude == latitude) && (m_longitude == longitude))
		return;
	if (m_latitude != latitude) {
		setLatitude(latitude);
	}
	if (m_longitude != longitude) {
		setLongitude(longitude);
	}
	emit coordinatesChanged(m_latitude, m_longitude);
}

void CityInfo::setLatitude(const QString& latitude) {
	if (m_latitude == latitude)
		return;
	m_latitude = latitude;
	emit latitudeChanged();
}
QString CityInfo::latitude() const {
	return m_latitude;
}

void CityInfo::setLongitude(const QString& longitude) {
	if (m_longitude == longitude)
		return;
	m_longitude = longitude;
	emit longitudeChanged();
}
QString CityInfo::longitude() const {
	return m_longitude;
}

void CityInfo::setWeather(const QString& weather) {
	if (m_weather == weather)
		return;
	m_weather = weather;
	emit weatherChanged();
}
QString CityInfo::weather() const {
	return m_weather;
}

void CityInfo::setTemperature(const QString& temperature) {
	if (m_temperature == temperature)
		return;
	m_temperature = temperature;
	emit temperatureChanged();
}
QString CityInfo::temperature() const {
	return m_temperature;
}

void CityInfo::setWeatherIcon(const bb::cascades::Image& weatherIcon) {
	m_weatherIcon = weatherIcon;
	emit weatherIconChanged();
}

QVariant CityInfo::weatherIcon() const {
	return QVariant::fromValue(m_weatherIcon);
}

void CityInfo::setLastObservation(const QString& lastObservation) {
	if (m_lastObservation == lastObservation)
		return;
	m_lastObservation = lastObservation;
	emit lastObservationChanged();
}

QString CityInfo::lastObservation() const {
	return m_lastObservation;
}
