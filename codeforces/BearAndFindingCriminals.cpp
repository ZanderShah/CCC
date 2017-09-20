#include <bits/stdc++.h>
using namespace std;

int n, m, a[100], ans = 0;

int main()
{
	scanf("%d %d", &n, &m);
	m--;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0, x, y; i < n; i++)
	{
		x = m - i;
		y = m + i;

		if (x == y)
			ans += a[x];
		else if (x >= 0 && y < n)
			ans += (a[x] && a[y] ? 2 : 0);
		else if (x >= 0)
			ans += a[x];
		else if (y < n)
			ans += a[y];
	}

	printf("%d", ans);

	return 0;
}