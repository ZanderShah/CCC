#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <unordered_map>
#include <map>
#include <bitset>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef unordered_map<int, int> umii;

int T, N, B, dp[5][3005];
vector<pii> C[5];

int comp(int t, int c) {
	if (t >= T)
		return 0;
	if (dp[t][c] != -1)
		return dp[t][c];
	int ret = -1;
	for (int i = 0; i < C[t].size(); i++)
		if (c + C[t][i].x <= B)
			ret = max(ret, comp(t + 1, c + C[t][i].x) + C[t][i].y);
	return dp[t][c] = ret;
}

int main() {
	scanf("%d %d", &T, &N);
	for (int i = 0, c, v, t; i < N; i++) {
		scanf("%d %d %d", &c, &v, &t);
		C[t - 1].pb(mp(c, v));
	}
	scanf("%d", &B);
	for (int i = 0; i < T; i++)
		for (int j = 0; j <= B; j++)
			dp[i][j] = -1;
	printf("%d\n", comp(0, 0));
}
