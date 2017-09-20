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

const int MAXN = 6005;

int N, a, b, w, lca, par[MAXN], depth[MAXN], sparse[MAXN][15], Q;
ll dist[MAXN];
vector<pii> adj[MAXN];
bool vis[MAXN];

void dfs(int i, int p, int l, ll d) {
	vis[i] = 1;
	par[i] = p;
	depth[i] = l;
	dist[i] = d;

	for (int j = 0; j < adj[i].size(); j++) {
		if (!vis[adj[i][j].x] && adj[i][j].x != p) {
			dfs(adj[i][j].x, i, l + 1, d + adj[i][j].y);
		}
	}
}

int query(int x, int y) {
	if (depth[x] < depth[y]) {
		swap(x, y);
	}

	int lg = 1;
	while ((1 << lg) <= depth[x]) {
		lg++;
	}
	lg--;

	for (int i = lg; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) {
			x = sparse[x][i];
		}
	}

	if (x == y) {
		return x;
	}

	for (int i = lg; i >= 0; i--) {
		if (sparse[x][i] != -1 && sparse[x][i] != sparse[y][i]) {
			x = sparse[x][i];
			y = sparse[y][i];
		}
	}

	return par[x];
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &w);
		adj[a].pb(mp(b, w));
		adj[b].pb(mp(a, w));
	}
	dfs(0, 0, 0, 0);

	memset(sparse, -1, sizeof sparse);

	for (int i = 0; i < N; i++) {
		sparse[i][0] = par[i];
	}

	for (int j = 1; (1 << j) < N; j++) {
		for (int i = 0; i < N; i++) {
			if (sparse[i][j - 1] != -1) {
				sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
			}
		}
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &a, &b);
		lca = query(a, b);
		printf("%lld\n", dist[a] + dist[b] - 2 * dist[lca]);
	}
}
