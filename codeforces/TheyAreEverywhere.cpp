#include <bits/stdc++.h>
using namespace std;

int n, a[52], b[52], k, t, best;
char c[100000];

int main()
{
	scanf("%d", &n);
	scanf("%s", &c);

	t = 0;
	for (int i = 0, x; i < n; i++)
	{
		x = (c[i] < 'a' ? c[i] - 'A' : c[i] - 'a' + 26);
		
		if (!b[x])
		{
			t++;
			b[x]++;
		}
	}

	best = n;

	for (int i = 0, j = 0, x, v; j < n; j++)
	{
		x = (c[i] < 'a' ? c[i] - 'A' : c[i] - 'a' + 26);
		v = (c[j] < 'a' ? c[j] - 'A' : c[j] - 'a' + 26);
		a[v]++;

		if (a[v] <= b[v])
			k++;

		if (k == t)
		{
			while (b[x] == 0 || (a[x] > b[x]))
			{
				if (a[x] > b[x])
					a[x]--;
				i++;
				x = (c[i] < 'a' ? c[i] - 'A' : c[i] - 'a' + 26);
			}

			best = min(best, j - i + 1);
		}
	}

	printf("%d", best);
}