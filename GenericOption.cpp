#include "GenericOption.h"



GenericOption::GenericOption(double expiry, double strike, OptionType type)
	: m_expiry(expiry), m_strike(strike), m_type(type)
{
}

GenericOption::GenericOption(const GenericOption& p)
	:m_expiry(p.m_expiry), m_strike(p.m_strike), m_type(p.m_type)
{
}

GenericOption& GenericOption::operator=(const GenericOption &p)
{
	if (&p != this)
	{
		this->m_expiry = p.m_expiry;
		this->m_strike = p.m_strike;
		this->m_type = p.m_type;
	}
	return *this;
}

GenericOption::~GenericOption()
{
}

double GenericOption::payoff(double p)
{
	if (m_type == OptionType_Call)
		return std::max(p - m_strike, 0.0);
	else
		return std::max(m_strike - p, 0.0);
}
