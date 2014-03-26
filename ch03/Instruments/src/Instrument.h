/*
 * Instrument.h
 *
 *  Created on: Dec 1, 2013
 *      Author: aludin
 */

#ifndef INSTRUMENT_H_
#define INSTRUMENT_H_
#include <QObject>

class Instrument : public QObject {
	Q_OBJECT
	Q_PROPERTY(QString symbol READ symbol WRITE setSymbol NOTIFY symbolChanged)
	Q_PROPERTY(double price READ price NOTIFY priceChanged)
public:
	Instrument(QObject* parent = 0);
	virtual ~Instrument();

	QString symbol() const;
	void setSymbol(const QString& symbol);

	virtual double price() const=0;
signals:
	void symbolChanged();
	void priceChanged();


private:
	QString m_symbol;
};

#endif /* INSTRUMENT_H_ */
