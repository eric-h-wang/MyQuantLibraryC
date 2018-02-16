#include "UpAndOutOption.h"



UpAndOutOption::UpAndOutOption(double expiry, double strike, OptionType type, double barrier)
	: SingleBarrierOption(expiry, strike, type, barrier)
{
}

UpAndOutOption::UpAndOutOption(const UpAndOutOption& p)
	: SingleBarrierOption(p)
{
}

UpAndOutOption& UpAndOutOption::operator=(const UpAndOutOption& p)
{
	if (this != &p)
	{
		this->m_expiry = p.m_expiry;
		this->m_strike = p.m_strike;
		this->m_type = p.m_type;
		this->m_barrier = p.m_barrier;
	}
	return *this;
}
UpAndOutOption::~UpAndOutOption()
{
}

double UpAndOutOption::BlackScholesPrice(double r,
										double d,
										double v,
										double spot)
{
	return 0;
}