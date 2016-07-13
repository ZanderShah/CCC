#include <bits/stdc++.h>
using namespace std;

long long m, low, high;

long long atLeast(long long x)
{
	long long ret = 0;

	for (long long i = 2; i <= 500000; i++)
	{
		long long a = i * i * i;
		ret += x / a;
	}

	return ret;
}

int main()
{
	cin >> m;

	low = 8;
	high = 1e17;

	while (low <= high)
	{
		if (atLeast((low + high) / 2) >= m)
			high = (low + high) / 2 - 1;
		else
			low = (low + high) / 2 + 1;
	}

	if (atLeast(low) == m)
		cout << low;
	else if (atLeast(high) == m)
		cout << high;
	else
		cout << -1;
	
	return 0;
}