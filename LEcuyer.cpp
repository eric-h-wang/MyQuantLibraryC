#include "LEcuyer.h"

const int LEcuyer::a1[3] = { 0,63308,-183326 };
const int LEcuyer::a2[3] = { 86098, 0, -539609 };
const int LEcuyer::m1 = 2147483647;
const int LEcuyer::m2 = 2147483479;
std::deque<int> LEcuyer::seed1 = { 1,2,3 };
std::deque<int> LEcuyer::seed2 = { 1,2,3 };

LEcuyer::LEcuyer()
{
}

void LEcuyer::setSeed(const int* seed)
{
	for (int i = 0; i < 3; ++i)
	{
		seed1[i] = *(seed + i);
		seed2[i] = *(seed + 3 + i);
	}
}

double LEcuyer::getUniform()
{
	int x1 = 0;
	int x2 = 0;
	for (int i = 0; i < 3; ++i)
	{
		x1 += (seed1[i] * a1[i]);
		x2 += (seed2[i] * a2[i]);
	}
	x1 = ((x1%m1) + m1) % m1;
	x2 = ((x2%m2) + m2) % m2;
	seed1.pop_front();
	seed1.push_back(x1);
	seed2.pop_front();
	seed2.push_back(x2);
	double x = (x1 - x2) % (m1 - 1);
	if (x < 0)x += (m1 - 1);
	if (x > 0) return x / m1;
	else return double(m1 - 1) / m1;
}
