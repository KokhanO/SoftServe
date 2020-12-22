#include "Iterator.h"

long long Iterator::operator++()
{
	return ++num_;
}

bool Iterator::operator<(long long boudary)
{
	return num_ * num_ < boudary;
}

long long Iterator::getNum()
{
	return num_;
}
