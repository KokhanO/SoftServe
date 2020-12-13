#include "Validator.h"
#include <iostream>
#include <thread>
#include <chrono>

void count(long long b, long long a, long long* res)
{
	while (b <= a)
	{
		if ((((b % 10000) / 1000) + ((b % 100000) / 10000) + ((b % 1000000) / 100000)) == (((b % 1000) / 100) + ((b % 100) / 10) + (b % 10)))
		{
			++(*res);
		}
		++b;
	}
}

using namespace std;
using namespace std::chrono;

int main()
{
	//79499
	long long a;
	std::cin >> a;
	long long b = 0;
	long long tmp1 = 0;
	long long tmp2 = 0;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	std::thread th(count, b, a/2, &tmp1);
	count(a / 2 + 1, a, &tmp2);
	th.join();
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2 - t1).count();

	std::cout << duration << '\t' << tmp1+tmp2;
}
