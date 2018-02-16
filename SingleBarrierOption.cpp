#include "SingleBarrierOption.h"



SingleBarrierOption::SingleBarrierOption(double expiry, double strike, OptionType type, double barrier)
	: GenericOption(expiry, strike, type), m_barrier(barrier)
{
}

SingleBarrierOption::SingleBarrierOption(const SingleBarrierOption& p)
	: GenericOption(p), m_barrier(p.m_barrier)
{
}

SingleBarrierOption& SingleBarrierOption::operator=(const SingleBarrierOption& p)
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

SingleBarrierOption::~SingleBarrierOption()
{
}


//double SingleBarrierOption::upAndOut