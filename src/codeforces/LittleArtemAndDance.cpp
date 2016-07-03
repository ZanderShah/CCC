#include <bits/stdc++.h>
using namespace std;

int n, q, ans[1000001];

int cycle(int a, int x)
{
	a = (a + x + n) % n;
	if (!a)
		a = n;
	return a;
}

int main()
{
	scanf("%d %d", &n, &q);

	int first = 1, second = 2;

	for (int i = 0, c, x; i < q; i++)
	{
		scanf("%d", &c);

		if (c == 1)
		{
			scanf("%d", &x);
			first = cycle(first, x);
			second = cycle(second, x);
		}
		else
		{
			first = cycle(first, (first % 2 ? 1 : -1));
			second = cycle(second, (second % 2 ? 1 : -1));
		}
	}

	for (int i = 1; i <= n; i += 2)
	{
		ans[first] = i;
		first = cycle(first, 2);
	}

	for (int i = 2; i <= n; i += 2)
	{
		ans[second] = i;
		second = cycle(second, 2);
	}

	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);

	return 0;
}