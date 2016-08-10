#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

const int p[6][3] = { { 0, 1, 2 }, { 0, 2, 1 }, { 1, 0, 2 }, { 1, 2, 0 }, { 2,
		0, 1 }, { 2, 1, 0 } };

int N, v[150001][3], dp[6][150001][3];

int go(int t, int i, int c)
{
	if (i >= N)
		return c == 2 ? 0 : 1 << 30;
	int& ret = dp[t][i][c];
	if (ret != -1)
		return ret;
	ret = go(t, i + 1, c) + v[i][p[t][c]];
	if (c <= 1)
		ret = min(ret, go(t, i + 1, c + 1) + v[i][p[t][c + 1]]);
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i][0]);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i][1]);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i][2]);
	memset(dp, -1, sizeof dp);

	int s = 1 << 30;
	for (int i = 0; i < 6; i++)
		s = min(s, go(i, 1, 0) + v[0][p[i][0]]);
	printf("%d", s);
}
