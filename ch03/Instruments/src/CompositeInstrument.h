/*
 * CompositeInstrument.h
 *
 *  Created on: Dec 1, 2013
 *      Author: aludin
 */

#ifndef COMPOSITEINSTRUMENT_H_
#define COMPOSITEINSTRUMENT_H_

#include "Instrument.h"

class CompositeInstrument : public Instrument {
	Q_OBJECT

public:
	CompositeInstrument(QObject* parent=0);
	virtual ~CompositeInstrument();

	void addInstrument(Instrument* instrument);
	bool removeInstrument(Instrument* instrument);
	const QList<Instrument*>& instruments();
	double price() const;

signals:
	void instrumentAdded();
	void instrumentRemoved();

private:
	QList<Instrument*> m_instruments;
};

#endif /* COMPOSITEINSTRUMENT_H_ */
