#include <iostream>

using namespace std;

int main()
{
	int k;
	cin >> k;

	for (int i = 1; i * i < k; ++i)
	{
		cout << i << ',';
	}
	
}
