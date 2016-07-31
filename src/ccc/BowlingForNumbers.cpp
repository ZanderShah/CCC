#include <bits/stdc++.h>
using namespace std;

int t, n, k, w, v[60001], dp[501][30001];

int bowl(int i, int j)
{
	if (i >= k || j > n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(bowl(i, j + 1), bowl(i + 1, j + w) + v[j + w - 1] - v[j - 1]);
}

int main() {
	scanf("%d", &t);

	for (int r = 0; r < t; r++)
	{
		scanf("%d %d %d", &n, &k, &w);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
			v[i] += v[i - 1];
		}
		for (int i = n + 1; i <= 60000; i++)
			v[i] = v[i - 1];
		memset(dp, -1, sizeof dp);
		printf("%d\n", bowl(0, 1));
	}
}
