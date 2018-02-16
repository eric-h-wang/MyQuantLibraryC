#pragma once
#include "GenericOption.h"

class SingleBarrierOption :
	public GenericOption
{
public:
	SingleBarrierOption(double expiry, double strike, OptionType type, double barrier);
	SingleBarrierOption(const SingleBarrierOption& p);
	SingleBarrierOption& operator=(const SingleBarrierOption& p);
	virtual ~SingleBarrierOption();
protected:
	double m_barrier;
};

