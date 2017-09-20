#include <bits/stdc++.h>
using namespace std;

int n, k, c[501];
bitset<501> dp[501][501];

int main()
{
	dp[0][0][0] = 1;

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);

	// [number of coins][total sum][subset sums]
	for (int i = 1; i <= n; i++)
	{
		dp[i][0][0] = 1;

		for (int j = 1; j <= k; j++)
		{
			dp[i][j] |= dp[i - 1][j];

			if (j >= c[i])
			{
				dp[i][j] |= dp[i - 1][j - c[i]] << c[i];
				dp[i][j] |= dp[i - 1][j - c[i]];
			}
		}
	}

	vector<int> ans;
	ans.push_back(0);
	for (int i = 1; i <= k; i++)
		if (dp[n][k][i])
			ans.push_back(i);

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);

	return 0;
}