/*
 * Option.cpp
 *
 *  Created on: Dec 2, 2013
 *      Author: aludin
 */

#include "Option.h"
#include <cmath>
#include <iostream>
using namespace std;

// The cumulative normal distribution function
double CND(double X) {

	double L, K, w;

	double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
	double const a4 = -1.821255978, a5 = 1.330274429;
	double const Pi = 3.141592653589793238462643;

	L = fabs(X);
	K = 1.0 / (1.0 + 0.2316419 * L);
	w = 1.0
			- 1.0 / sqrt(2 * Pi) * exp(-L * L / 2)
					* (a1 * K + a2 * K * K + a3 * pow(K, 3) + a4 * pow(K, 4)
							+ a5 * pow(K, 5));
	if (X < 0) {
		w = 1.0 - w;
	}
	return w;
}

Option::Option(QObject* parent) :
		Instrument(parent), m_type(Option::CALL), m_strike(0), m_spot(0), m_volatility(
				0), m_riskfreeRate(0), m_timeToMaturity(0) {
}

Option::~Option() {
	std::cout << "Option was deleted" << std::endl;
}

double Option::price() const {
	double d1, d2;

	d1 = (log(m_spot / m_strike)
			+ (m_riskfreeRate + m_volatility * m_volatility / 2)
					* m_timeToMaturity)
			/ (m_volatility * sqrt(m_timeToMaturity));
	d2 = d1 - m_volatility * sqrt(m_timeToMaturity);

	switch (m_type) {
	case CALL:
		return m_spot * CND(d1)
				- m_strike * exp(-m_riskfreeRate * m_timeToMaturity) * CND(d2);
	case PUT:
		return m_strike * exp(-m_riskfreeRate * m_timeToMaturity) * CND(-d2)
				- m_spot * CND(-d1);
	default:
		//
		return 0;
	}
}

double Option::riskfreeRate() const {
	return m_riskfreeRate;
}

void Option::setRiskfreeRate(double riskfreeRate) {
	if (m_riskfreeRate == riskfreeRate)
		return;
	m_riskfreeRate = riskfreeRate;
	emit riskfreeRateChanged();
	emit priceChanged();
}

double Option::spot() const {
	return m_spot;
}

void Option::setSpot(double spot) {
	if (m_spot == spot)
		return;
	m_spot = spot;
	emit spotChanged();
	emit priceChanged();
}

double Option::strike() const {
	return m_strike;
}

void Option::setStrike(double strike) {
	if (m_strike == strike)
		return;
	m_strike = strike;
	emit strikeChanged();
	emit priceChanged();
}

double Option::timeToMaturity() const {
	return m_timeToMaturity;
}

void Option::setTimeToMaturity(double timeToMaturity) {
	if (m_timeToMaturity == timeToMaturity)
		return;
	m_timeToMaturity = timeToMaturity;
	emit maturityChanged();
	emit priceChanged();
}

Option::OptionType Option::optionType() const {
	return m_type;
}

void Option::setOptionType(Option::OptionType type) {
	if (m_type == type)
		return;
	m_type = type;
	emit typeChanged();
	emit priceChanged();
}

double Option::volatility() const {
	return m_volatility;
}

void Option::setVolatility(double volatility) {
	if (m_volatility == volatility)
		return;
	m_volatility = volatility;
	emit volatilityChanged();
	emit priceChanged();
}
