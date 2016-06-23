#include <bits/stdc++.h>
using namespace std;

long long n, x, d;
char c;

int main()
{
	cin >> n >> x;
	long long cur = x;
	int sad = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		cin >> d;

		if (c == '-')
		{
			if (d > cur)
				sad++;
			else
				cur -= d;
		}
		else
		{
			cur += d;
		}
	}

	cout << cur << " " << sad;

	return 0;
}