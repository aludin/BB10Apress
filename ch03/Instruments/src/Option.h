/*
 * Option.h
 *
 *  Created on: Dec 2, 2013
 *      Author: aludin
 */

#ifndef OPTION_H_
#define OPTION_H_
#include "Instrument.h"

class Option: public Instrument {
Q_OBJECT
Q_ENUMS(OptionType)

Q_PROPERTY(OptionType type READ optionType WRITE setOptionType NOTIFY typeChanged)
Q_PROPERTY(double riskfreeRate READ riskfreeRate WRITE setRiskfreeRate NOTIFY riskfreeRateChanged)
Q_PROPERTY(double spot READ spot WRITE setSpot NOTIFY spotChanged)
Q_PROPERTY(double strike READ strike WRITE setStrike NOTIFY strikeChanged)
Q_PROPERTY(double maturity READ timeToMaturity WRITE setTimeToMaturity NOTIFY maturityChanged)
Q_PROPERTY(double volatility READ volatility WRITE setVolatility NOTIFY volatilityChanged)


public:
	enum OptionType {
		CALL, PUT
	};

	Option(QObject* parent = 0);
	virtual ~Option();

	double price() const;

	double riskfreeRate() const;
	void setRiskfreeRate(double riskfreeRate);

	double spot() const;
	void setSpot(double spot);

	double strike() const;
	void setStrike(double strike);

	double timeToMaturity() const;
	void setTimeToMaturity(double timeToMaturity);

	OptionType optionType() const;
	void setOptionType(OptionType type);

	double volatility() const;
	void setVolatility(double volatility);

signals:
	//void priceChanged();
	void typeChanged();
	void spotChanged();
	void volatilityChanged();
	void strikeChanged();
	void riskfreeRateChanged();
	void maturityChanged();

private:
	OptionType m_type;
	double m_strike;
	double m_spot;
	double m_volatility;
	double m_riskfreeRate;
	double m_timeToMaturity;
};

#endif /* OPTION_H_ */
