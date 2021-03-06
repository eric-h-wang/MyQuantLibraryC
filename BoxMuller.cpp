#include "BoxMuller.h"


double BoxMuller::getNormal()
{
	double result;

	double x;
	double y;

	double sizeSquared;
	do
	{
		x = 2.0*rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2.0*rand() / static_cast<double>(RAND_MAX) - 1;
		sizeSquared = x*x + y*y;
	} while
		(sizeSquared >= 1.0);

	result = x*sqrt(-2 * std::log(sizeSquared) / sizeSquared);

	return result;
}

void BoxMuller::setSeed(int x)
{
	if (x >= 0) srand(x);
	else srand(time(NULL));
}

