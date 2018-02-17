#pragma once
#include <deque>
class LEcuyer
{
public:
	virtual ~LEcuyer() = 0;
	static void setSeed(const int*);
	static double getUniform();
private:
	LEcuyer();
	static std::deque<int> seed1;
	static std::deque<int> seed2;
	static const int a1[3];
	static const int a2[3];
	static const int m1;
	static const int m2;
};

