#include <bits/stdc++.h>
using namespace std;

int n, a[100], dp[101][2][2];

// # gym contest
// 0 no no
// 1 no yes
// 2 yes no
// 3 yes yes

int go(int x, int y, int z)
{
	if (x >= n)
		return 0;
	if (dp[x][y][z] != -1)
		return dp[x][y][z];

	int ret = min(101, go(x + 1, 0, 0) + 1);

	if ((a[x] == 1 || a[x] == 3) && !z)
	{
		ret = min(ret, go(x + 1, 0, 1));
	}
	if ((a[x] == 2 || a[x] == 3) && !y)
	{
		ret = min(ret, go(x + 1, 1, 0));
	}

	return dp[x][y][z] = ret;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++)
		dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;

	cout << go(0, 0, 0);

	return 0;
}