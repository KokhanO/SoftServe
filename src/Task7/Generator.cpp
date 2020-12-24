#include "Generator.h"
#include <cmath>

Generator::Generator(long long current_num):current_num_(current_num)
{
}

long long Generator::operator++()
{
	return ++current_num_;
}


bool Generator::operator<(const long long& top_border)
{
	return current_num_ < std::ceil(std::sqrt(top_border));
}

long long Generator::getCurrentNum() const
{
	return current_num_;
}