#include <bits/stdc++.h>
using namespace std;

int n, m, k, dp[1001][1001][11][2];
string x, y;

int go(int a, int b, int c, int d)
{
	if (a > x.length() || b > y.length())
		return 0;
	if (dp[a][b][c][d] != -1)
		return dp[a][b][c][d];
	int ret = 0;
	if (a < x.length() && b < y.length() && x[a] == y[b])
		if (!d && c != k)
			ret = max(ret, go(a + 1, b + 1, c + 1, 1) + 1);
		else if (d)
			ret = max(ret, go(a + 1, b + 1, c, 1) + 1);
	ret =  max(ret, max(go(a + 1, b, c, 0), go(a, b + 1, c, 0)));
	return dp[a][b][c][d] = ret;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	cin >> x >> y;
	memset(dp, -1, sizeof dp);
	printf("%d", go(0, 0, 0, 0));
	return 0;
}