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

const int MAXN = 1e5 + 5, MOD = 1e9;

int N, M, A, B, dp[MAXN], clr[MAXN];
vector<int> adj[MAXN];
bool keep[MAXN], large = 0;

bool trim(int i) {
	bool ret = (i == 2);

	clr[i] = 1;
	for (int j = 0; j < adj[i].size(); j++) {
		if (clr[adj[i][j]]) {
			ret |= keep[adj[i][j]];
		} else {
			ret |= trim(adj[i][j]);
		}
	}

	return keep[i] = ret;
}

bool cycle(int i) {
	bool ret = 0;

	clr[i] = 1;
	for (int j = 0; j < adj[i].size(); j++) {
		if (!keep[adj[i][j]]) {
			continue;
		}
		if (clr[adj[i][j]] == 0) {
			ret |= cycle(adj[i][j]);
		} else if (clr[adj[i][j]] == 1) {
			return 1;
		}
	}
	clr[i] = 2;

	return ret;
}

int dfs(int i) {
	if (i == 2) {
		return 1;
	}
	if (dp[i] != -1) {
		return dp[i];
	}
	int ret = 0;
	for (int j = 0; j < adj[i].size(); j++) {
		if (!keep[adj[i][j]]) {
			continue;
		}
		ret = ret + dfs(adj[i][j]);
		if (ret > MOD) {
			large = 1;
			ret %= MOD;
		}
	}
	return dp[i] = ret;
}

// Race starts at 1 and ends at 2

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &A, &B);
		adj[A].pb(B);
	}

	trim(1);


	memset(clr, 0, sizeof clr);
	if (cycle(1)) {
		printf("inf\n");
		return 0;
	}

	memset(dp, -1, sizeof dp);

	int ans = dfs(1);
	if (large) {
		printf("%09d\n", ans);
	} else {
		printf("%d\n", ans);
	}
}
