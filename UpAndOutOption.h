#pragma once
#include "SingleBarrierOption.h"
class UpAndOutOption :
	public SingleBarrierOption
{
public:
	UpAndOutOption(double expiry, double strike, OptionType type, double barrier);
	UpAndOutOption(const UpAndOutOption& p);
	UpAndOutOption& operator=(const UpAndOutOption& p);
	virtual ~UpAndOutOption();

	double BlackScholesPrice(double r,
							double d,
							double v,
							double spot);
};

