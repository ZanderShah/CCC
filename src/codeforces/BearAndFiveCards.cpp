#include <bits/stdc++.h>
using namespace std;

int a[5], total, best;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
		total += a[i];
		best += a[i];
	}

	for (int i = 0; i < 5; i++)
		for (int j = i + 1; j < 5; j++)
			for (int k = j + 1; k < 5; k++)
			{
				if (a[i] == a[j] && a[i] == a[k])
					best = min(best, total - a[i] * 3);
				else if (a[i] == a[j] || a[i] == a[k])
					best = min(best, total - a[i] * 2);
				else if (a[k] == a[j])
					best = min(best, total - a[k] * 2);
			}

	cout << best;
}