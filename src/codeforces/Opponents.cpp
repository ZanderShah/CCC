#include <bits/stdc++.h>
using namespace std;

int n, d;
string s;

int main()
{
	cin >> n >> d;

	int best = 0, run = 0;

	for (int i = 0; i < d; i++)
	{
		cin >> s;

		int opp = 0;
		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				opp++;

		if (opp == n)
		{
			best = max(best, run);
			run = 0;
		}
		else
			run++;
	}

	cout << max(best, run);
}