#include <bits/stdc++.h>
using namespace std;

struct Apple
{
	string e;
	int v, a, b, c;
} apples[11];

int N, R, S, dp[1001][1001], v, a, b;
string e;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> R >> S;

	for (int i = 1; i <= N; i++)
	{
		cin >> e >> v >> a >> b;
		apples[i] = { e, v, a, b, 0 };
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= R; j++)
			for (int k = 1; k <= S; k++)
			{
				if (j - apples[i].a >= 0 && k - apples[i].b >= 0)
					dp[j][k] = max(dp[j][k], dp[j - apples[i].a][k - apples[i].b] + apples[i].v);
			}

	cout << dp[R][S] << endl;

	for (int j = R, k = S; dp[j][k]; )
		for (int i = 1; i <= N; i++)
			if (j - apples[i].a >= 0 && k - apples[i].b >= 0 && dp[j][k] == dp[j - apples[i].a][k - apples[i].b] + apples[i].v)
			{	
				j -= apples[i].a;
				k -= apples[i].b;
				apples[i].c++;
			}

	for (int i = 1; i <= N; i++)
		cout << apples[i].e << " " << apples[i].c << endl;
}
