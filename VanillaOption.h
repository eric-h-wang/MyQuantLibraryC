#pragma once
#include "GenericOption.h"
#include "Normal.h"

class VanillaOption :
	public GenericOption
{
public:
	VanillaOption(double expiry, double strike, OptionType type);
	VanillaOption(const VanillaOption&);
	VanillaOption& operator=(const VanillaOption&);
	virtual ~VanillaOption();

	virtual double BlackScholesPrice(double r,		//interest rate
									double d,		//dividend rate
									double v,		//volatility
									double spot);	//spot price
};
