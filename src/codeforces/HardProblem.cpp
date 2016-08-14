#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n;
long long dp[100001][2], c[100001];
string s[100001][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	for (int i = 0; i < n; i++)
	{
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(s[i][1].begin(), s[i][1].end());
		dp[i][0] = dp[i][1] = -1;
	}

	// 0 -> No swap, 1 -> Swap
	dp[0][0] = 0;
	dp[0][1] = c[0];
	for (int i = 1; i < n; i++)
	{
		if (dp[i - 1][0] != -1 && s[i][0] >= s[i - 1][0])
			dp[i][0] = dp[i][0] == -1 ? dp[i - 1][0] : min(dp[i][0], dp[i - 1][0]);

		if (dp[i - 1][1] != -1 && s[i][0] >= s[i - 1][1])
			dp[i][0] = dp[i][0] == -1 ? dp[i - 1][1] : min(dp[i][0], dp[i - 1][1]);

		if (dp[i - 1][0] != -1 && s[i][1] >= s[i - 1][0])
			dp[i][1] = dp[i][1] == -1 ? dp[i - 1][0] + c[i] : min(dp[i][1], dp[i - 1][0] + c[i]);

		if (dp[i - 1][1] != -1 && s[i][1] >= s[i - 1][1])
			dp[i][1] = dp[i][1] == -1 ? dp[i - 1][1] + c[i] : min(dp[i][1], dp[i - 1][1] + c[i]);
	}

	if (dp[n - 1][0] == -1 || dp[n - 1][1] == -1)
		cout << max(dp[n - 1][0], dp[n - 1][1]);
	else
		cout << min(dp[n - 1][0], dp[n - 1][1]);
}
