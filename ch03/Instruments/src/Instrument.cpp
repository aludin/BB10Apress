/*
 * Instrument.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: aludin
 */

#include "Instrument.h"

Instrument::Instrument(QObject* parent) : QObject(parent), m_symbol(""){

}

Instrument::~Instrument() {
	// TODO Auto-generated destructor stub
}

void Instrument::setSymbol(const QString& symbol){
	m_symbol = symbol;
	emit symbolChanged();
}

QString Instrument::symbol() const{
	return m_symbol;
}
