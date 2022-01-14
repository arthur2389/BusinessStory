#ifndef MATHSERVICES_H
#define MATHSERVICES_H
#pragma once

#include <random>
#include <vector>

class MathServices  
{
	public:
		static std::vector<double> get_rands_with_average(double average, double range, int size);

};
#endif