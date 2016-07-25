#include <bits/stdc++.h>
using namespace std;

int n, H[1001], E[1001], P[1001], s;
pair<int, int> dp[51][1001];

int v(int i, int k)
{
	return H[i] * k - E[i] * k * (k - 1) / 2;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d %d", &H[i], &E[i], &P[i]);
	scanf("%d", &s);

	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= s; j++)
		{
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; j - P[i] * k >= 0 && v(i, k) >= 0; k++)
			{
				if (dp[i][j].first < dp[i - 1][j - P[i] * k].first + v(i, k))
				{
					dp[i][j].first = dp[i - 1][j - P[i] * k].first + v(i, k);
					dp[i][j].second = dp[i - 1][j - P[i] * k].second + k;
				}
				else if (dp[i][j].first == dp[i - 1][j - P[i] * k].first + v(i, k))
					dp[i][j].second = min(dp[i][j].second, dp[i - 1][j - P[i] * k].second + k);
			}
		}

	printf("%d\n%d\n", dp[n][s].first, dp[n][s].second);
}
