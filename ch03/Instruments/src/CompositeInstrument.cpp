/*
 * CompositeInstrument.cpp
 *
 *  Created on: Dec 1, 2013
 *      Author: aludin
 */

#include "CompositeInstrument.h"
#include <iostream>
using namespace std;

CompositeInstrument::CompositeInstrument(QObject* parent) : Instrument(parent) {

}

CompositeInstrument::~CompositeInstrument() {
	cout << "~CompositeInstrument()" << endl;
}

void CompositeInstrument::addInstrument(Instrument* instrument){
	m_instruments.append(instrument);
	instrument->setParent(this);
	emit instrumentAdded();
}

const QList<Instrument*>& CompositeInstrument::instruments(){
	return m_instruments;
}

bool CompositeInstrument::removeInstrument(Instrument* instrument){
	if(m_instruments.contains(instrument)){
		m_instruments.removeOne(instrument);
		instrument->setParent(0);
		emit instrumentRemoved();
		return true;
	}
	return false;
}

double CompositeInstrument::price() const {
	double price = 0;
	for(int i = 0; i < m_instruments.length(); i++){
		price += m_instruments[i]->price();
	}
	return price;
}

