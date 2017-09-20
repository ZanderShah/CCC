#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

const int MAXN = 105;

int n, m, k, c[MAXN], p[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN];

ll solve(int tree, int groups, int lastColour) {
	if (tree == n)
		return groups == k ? 0 : 1e14;
	if (groups > k)
		return 1e14;
	if (dp[tree][groups][lastColour] != -1)
		return dp[tree][groups][lastColour];

	if (c[tree])
		return dp[tree][groups][lastColour] = solve(tree + 1,
				groups + (c[tree] == lastColour ? 0 : 1), c[tree]);

	ll ret = 1e14;

	for (int colour = 1; colour <= m; colour++)
		ret = min(ret,
				solve(tree + 1, groups + (colour == lastColour ? 0 : 1), colour)
						+ p[tree][colour]);

	return dp[tree][groups][lastColour] = ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &p[i][j]);
	memset(dp, -1, sizeof dp);

	cout << (solve(0, 0, 0) < 1e14 ? solve(0, 0, 0) : -1);
}
