#include <iostream>

using namespace std;

int main()
{
	unsigned long long a;
	unsigned long long b;

	cin >> a;
	cin.ignore(255, ',');
	cin >> b;
	unsigned long long arr[2];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 0; arr[i % 2] <= b;++i)
	{
		if (arr[i % 2] >= a)
		{
			cout << arr[i % 2] << endl;
		}
		arr[i % 2] = arr[(i + 1) % 2] + arr[i % 2];
	}
}