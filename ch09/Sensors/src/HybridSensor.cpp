/*
 * HybridSensor.cpp
 *
 *  Created on: Dec 9, 2013
 *      Author: aludin
 */

#include "HybridSensor.h"

using namespace QtMobility;

HybridSensor::HybridSensor(QObject* parent) :
		QObject(parent), m_accelerometer(new QAccelerometer(this)), m_lightSensor(
				new QLightSensor(this)), m_accelX(0), m_accelY(0), m_accelZ(0), m_lux(
				0) {
	m_accelerometer->setAccelerationMode(QAccelerometer::User);
	m_accelerometer->setSkipDuplicates(true);
	m_accelerometer->setAlwaysOn(false);
	m_accelerometer->setAxesOrientationMode(QAccelerometer::FixedOrientation);
	m_accelerometer->addFilter(this);

	bool result = QObject::connect(m_accelerometer, SIGNAL(readingChanged()),
			this, SLOT(onAccellerationChanged()));
	Q_ASSERT(result);

	result = QObject::connect(m_lightSensor, SIGNAL(readingChanged()), this,
			SLOT(onLightChanged()));
	Q_ASSERT(result);
}

HybridSensor::~HybridSensor() {

}

bool HybridSensor::filter(QAccelerometerReading *reading) {
	double x = reading->x();
	double y = reading->y();
	double z = reading->z();
	if (x * x + y * y + z * z > 0.1) {
		return true;
	} else {
		return false;
	}
}

double HybridSensor::accelX() {
	return m_accelX;
}

double HybridSensor::accelY() {
	return m_accelY;
}

double HybridSensor::accelZ() {
	return m_accelZ;
}

double HybridSensor::lux() {
	return m_lux;
}

bool HybridSensor::checkForAccelerometer() {
	QList<QByteArray> sensorType = QSensor::sensorTypes();
	return sensorType.contains(QAccelerometer::type);
}

void HybridSensor::start() {
	m_accelerometer->start();
	m_lightSensor->start();
}

void HybridSensor::stop() {
	m_accelerometer->stop();
	m_lightSensor->stop();
}

void HybridSensor::onAccellerationChanged() {
	QAccelerometerReading* reading = m_accelerometer->reading();

	m_accelX = reading->x();
	m_accelY = reading->y();
	m_accelZ = reading->z();

	emit accelChanged();
}

void HybridSensor::onLightChanged() {
	QLightReading* reading = m_lightSensor->reading();
	m_lux = reading->lux();
	emit luxChanged();
}

