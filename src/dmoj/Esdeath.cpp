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

const int MAXN = 5005;

int N, S, par[MAXN], depth[MAXN], vis[MAXN];
vector<int> adj[MAXN];
pii ord[MAXN];

void pre(int i, int p) {
	depth[i] = depth[p] + 1;
	ord[i] = mp(depth[i], i);
	par[i] = p;
	for (int j = 0; j < adj[i].size(); j++) {
		if (adj[i][j] != p) {
			pre(adj[i][j], i);
		}
	}
}

int back(int i, int d) {
	return d > 0 ? back(par[i], d - 1) : i;
}

void visit(int i, int d) {
	vis[i] = d;
	if (d == 1) return;
	for (int j = 0; j < adj[i].size(); j++) {
		if (vis[adj[i][j]] <= d - 1) {
			visit(adj[i][j], d - 1);
		}
	}
}

int required(int d) {
	memset(vis, 0, sizeof vis);

	int ret = 0;
	for (int i = N; i >= 1; i--) {
		if (vis[ord[i].y]) continue;
		// Go D nodes backwards and mark downwards
		visit(back(ord[i].y, d), d + 1);
		ret++;
	}
	return ret;
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0, u, v; i < N - 1; i++) {
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	pre(1, 1);
	sort(ord + 1, ord + 1 + N);

	int lo = 0, hi = N, mid = (lo + hi) >> 1;
	while (lo <= hi) {
		if (S < required(mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
		mid = (lo + hi) >> 1;
	}
	printf("%d\n", lo);
}
