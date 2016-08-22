#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int n, m, v;
bool p[10000], dp[101][10001];
vector<int> fp;

int main()
{
	for (int i = 2; i < 10000; i++)
		if (!p[i])
		{
			for (int j = 2 * i; j < 10000; j += i)
				p[j] = 1;
			fp.pb(i);
		}

	dp[0][0] = 1;
	scanf("%d %d", &n, &m);
	for (int i = 1, v; i <= m; i++)
	{
		scanf("%d", &v);
		for (int j = 0; j < fp.size(); j++)
			if (v * fp[j] <= n)
				for (int k = 0; k <= n - v * fp[j]; k++)
					if (dp[i - 1][k])
						dp[i][k + v * fp[j]] = 1;
	}

	for (int i = 0; i < fp.size(); i++)
		if (dp[m][fp[i]])
		{
			cout << "its primetime";
			return 0;
		}
	cout << "not primetime";
}
