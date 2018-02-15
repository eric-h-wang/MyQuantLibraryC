#pragma once

const double OneOverRootTwoPi = 0.398942280401433;

class Normal
{
public:
	static double normalDensity(double x);
	static double cumulativeNormal(double x);
	static double inverseNormalDensity(double x);
private:
	Normal();
	virtual ~Normal()=0;
};

