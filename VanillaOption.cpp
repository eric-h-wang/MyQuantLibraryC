#include "VanillaOption.h"


VanillaOption::VanillaOption(double expiry, double strike, OptionType type)
	: GenericOption(expiry, strike, type)
{
}

VanillaOption::VanillaOption(const VanillaOption& p)
	: GenericOption(p)
{

}

VanillaOption& VanillaOption::operator=(const VanillaOption& p)
{
	if (this != &p)
	{
		this->m_expiry = p.m_expiry;
		this->m_strike = p.m_strike;
		this->m_type = p.m_type;
	}
	return *this;
}

VanillaOption::~VanillaOption()
{
}


double VanillaOption::BlackScholesPrice(double r,
	double d,
	double v,
	double spot)
{
	double std = v*std::sqrt(m_expiry);
	double d1 = (std::log(spot / m_strike) + (r - d)*m_expiry) / std + 0.5*std;
	double d2 = d1 - std;
	if (m_type == OptionType_Call)
	{
		return spot*std::exp(-d*m_expiry)*Normal::cumulativeNormal(d1)
			- m_strike*std::exp(-r*m_expiry)*Normal::cumulativeNormal(d2);
	}
	else
	{
		return m_strike*std::exp(-r*m_expiry)*Normal::cumulativeNormal(-d2)
			- spot*std::exp(-d*m_expiry)*Normal::cumulativeNormal(-d1);
	}
}
