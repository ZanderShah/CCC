#include <bits/stdc++.h>
using namespace std;

int n, m, a = -1, b = 1e9;

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0, x, y; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		if (y < x)
		{
			int t = x;
			x = y;
			y = t;
		}

		if (a > y || b < x)
		{
			cout << 0;
			return 0;
		}
		else
		{
			a = max(a, x);
			b = min(b, y);
		}
	}
	
	if (a == -1)
	{
		a = 1;
		b = n;
	}
	
	cout << max(b - a, 0);
	return 0;
}