#pragma once
#include <cstdlib>
#include <algorithm>
#include <time.h>

class BoxMuller
{
public:
	virtual ~BoxMuller() = 0;
	static double getNormal();	//Box Muller

	static void setSeed(int x);
private:
	BoxMuller() {};
};

