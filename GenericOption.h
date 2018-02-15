#pragma once
#include <algorithm>

enum OptionType {
	OptionType_Call,
	OptionType_Put
};
class GenericOption
{
public:
	GenericOption(double expiry, double strike, OptionType type);
	GenericOption(const GenericOption&);
	GenericOption& operator=(const GenericOption&);
	virtual ~GenericOption();
	virtual double payoff(double p);		//p: underlying price at expiration
protected:
	double m_expiry;
	double m_strike;
	OptionType m_type;
};

