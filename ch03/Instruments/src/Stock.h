/*
 * Stock.h
 *
 *  Created on: Dec 2, 2013
 *      Author: aludin
 */

#ifndef STOCK_H_
#define STOCK_H_
#include "Instrument.h"


class Stock: public Instrument {
Q_OBJECT
Q_PROPERTY(double spot READ spot WRITE setSpot NOTIFY spotChanged)
public:
	Stock(QObject* parent = 0);
	virtual ~Stock();

	double spot() const;
	void setSpot(double spot);

	double price() const;
signals:
	void spotChanged();
private:
	double m_spot;
};

#endif /* STOCK_H_ */
