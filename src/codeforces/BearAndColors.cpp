#include <bits/stdc++.h>
using namespace std;

int n, v[5000], ans[5001], c[5001], b = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < n; i++)
	{
		memset(c, 0, sizeof c);

		for (int j = i; j < n; j++)
		{
			c[v[j]]++;
			if (c[v[j]] > c[b] || (c[v[j]] == c[b] && v[j] < b))
				b = v[j];
			ans[b]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}