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
#include <string>
#include <cstring>
#include <cassert>

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do {while((x=getchar())<'0') ; for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0') ; } while(0)
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
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;

const int MAXN = 200005;

int N, K[MAXN], cnt[MAXN];
vector<int> adj[MAXN];
unordered_map<int, umii> dp;
ll ans = 0;

void pre(int i, int p) {
	cnt[i] = 1;
	for (int j = 0; j < adj[i].size(); j++) {
		if (adj[i][j] == p) continue;
		pre(adj[i][j], i);
		cnt[i] += cnt[adj[i][j]];
	}
}

inline int count(int i, int p) {
	if (p == -1) return 0;
	return cnt[i] < cnt[p] ? cnt[i] : cnt[1] - cnt[p];
}

pii lastVis[MAXN];

ll dfs(int i, int p) {
	if (dp[i].find(p) != dp[i].end()) {
		return dp[i][p];
	}

	ll ret = 0;

	if (p != -1 && lastVis[i].x != -1) {
		ret = lastVis[i].y - dfs(p, i) + dfs(lastVis[i].x, i);
	} else {
		for (int j = 0; j < adj[i].size(); j++) {
			if (adj[i][j] == p) continue;
			ret += dfs(adj[i][j], i);
		}
	}

	lastVis[i] = mp(p, ret);

	ret += count(i, p);
	return dp[i][p] = ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &K[i]);
		lastVis[i] = mp(-1, 0);
	}
	for (int i = 0, u, v; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pre(1, -1);

	for (int i = 1; i <= N; i++) {
		ll total = dfs(i, -1);
		ll sum = total;

		for (int j = 0; j < adj[i].size(); j++) {
			sum += (total - dp[adj[i][j]][i]) * count(adj[i][j], i);
		}

		ans += sum * K[i];
	}

	printf("%lld\n", ans);
}
