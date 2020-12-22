#pragma once


class Iterator
{
public:
	Iterator(long long num) :num_(num)
	{

	}
	long long operator ++();
	bool operator <(long long boudary);
	long long getNum();
private:
	long long num_;
};