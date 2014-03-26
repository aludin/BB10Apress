/*
 * Stock.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: aludin
 */

#include "Stock.h"
#include <iostream>

Stock::Stock(QObject* parent) : Instrument(parent), m_spot(0) {

}

Stock::~Stock() {
	std::cout << "Stock was deleted" << std::endl;
}

double Stock::price() const{
    return spot();
}

double Stock::spot() const{
	return m_spot;
}

void Stock::setSpot(double spot){
	m_spot = spot;
	emit spotChanged();
}

