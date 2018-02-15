#pragma once
#include "GenericOption.h"

enum BarrierType {
	UP_AND_IN,
	UP_AND_OUT,
	DOWN_AND_IN,
	DOWN_AND_OUT
};
class SingleBarrierOption :
	public GenericOption
{
public:
	SingleBarrierOption(double expiry, double strike, OptionType type, double barrier, BarrierType btype);
	SingleBarrierOption(const SingleBarrierOption& p);
	SingleBarrierOption& operator=(const SingleBarrierOption& p);
	virtual ~SingleBarrierOption();

	double BlackScholesPrice(double r,
		double d,
		double v,
		double spot);

private:
	double m_barrier;
	BarrierType m_btype;

	double upAndOut(double r, double d, double v, double spot);
	double upAndIn(double r, double d, double v, double spot);
	double downAndOut(double r, double d, double v, double spot);
	double downAndIn(double r, double d, double v, double spot);
};

