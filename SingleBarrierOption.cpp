#include "SingleBarrierOption.h"



SingleBarrierOption::SingleBarrierOption(double expiry, double strike, OptionType type, double barrier, BarrierType btype)
	: GenericOption(expiry, strike, type), m_barrier(barrier), m_btype(btype)
{
}

SingleBarrierOption::SingleBarrierOption(const SingleBarrierOption& p)
	: GenericOption(p), m_barrier(p.m_barrier), m_btype(p.m_btype)
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
		this->m_btype = p.m_btype;
	}
	return *this;
}

SingleBarrierOption::~SingleBarrierOption()
{
}

double SingleBarrierOption::BlackScholesPrice(double r,
											double d,
											double v,
											double spot)
{
	switch (m_btype)
	{
	case UP_AND_IN:
		return upAndIn(r, d, v, spot); break;
	case UP_AND_OUT:
		return upAndOut(r, d, v, spot); break;
	case DOWN_AND_IN:
		return downAndIn(r, d, v, spot); break;
	case DOWN_AND_OUT:
		return downAndOut(r, d, v, spot); break;
	}
}