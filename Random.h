#pragma once
#include <cstdlib>
#include <algorithm>
#include <time.h>

class Random
{
public:
	virtual ~Random() = 0;
	static double getNormal();	//Box Muller
	static void setSeed(int x);
private:
	Random() {};
};
