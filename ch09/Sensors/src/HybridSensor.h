/*
 * HybridSensor.h
 *
 *  Created on: Dec 9, 2013
 *      Author: aludin
 */

#ifndef HYBRIDSENSOR_H_
#define HYBRIDSENSOR_H_

#include <QObject>
#include <QtSensors/QAccelerometer>
#include <QtSensors/QLightSensor>
#include <QtSensors/QAccelerometerFilter>


class HybridSensor : public QObject, public QtMobility::QAccelerometerFilter{
	Q_OBJECT
	Q_PROPERTY(qreal accelX READ accelX NOTIFY accelChanged)
	Q_PROPERTY(qreal accelY READ accelY NOTIFY accelChanged)
	Q_PROPERTY(qreal accelZ READ accelZ NOTIFY accelChanged)
	Q_PROPERTY(qreal lux READ lux NOTIFY luxChanged)
public:
	HybridSensor(QObject* parent = 0);
	virtual ~HybridSensor();

	virtual bool filter(QtMobility::QAccelerometerReading *reading);

signals:
	void accelChanged();
	void luxChanged();

public slots:
	void start();
	void stop();
	void onAccellerationChanged();
	void onLightChanged();

public:
	double accelX();
	double accelY();
	double accelZ();
	double lux();

private:

	bool checkForAccelerometer();

    QtMobility::QAccelerometer* m_accelerometer;
    QtMobility::QLightSensor* m_lightSensor;

    double m_accelX;
    double m_accelY;
    double m_accelZ;
    double m_lux;
};

#endif /* HYBRIDSENSOR_H_ */
