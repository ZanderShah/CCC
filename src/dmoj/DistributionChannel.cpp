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

const int MAXN = 100005;

struct Edge {
	int a, b, c;
	Edge(int a, int b, int c) : a(a), b(b), c(c) {
	}
	bool operator< (const Edge e) const {
		return c < e.c;
	}
};

// MST
ll cost = 0, best = (ll) 1 << 60;
vector<Edge> e, no;
vector<pii> mst[MAXN];

// Precompute
int N, M, par[MAXN], depth[MAXN], size[MAXN];

// HLD
int chain[MAXN], head[MAXN], chainPos, val[MAXN], basePos, base[MAXN];

struct DisjointSet {
	struct Node {
		int p, sz;
		Node(int p) : p(p), sz(1) {
		}
	};

	int N;
	vector<Node> v;

	DisjointSet(int N) : N(N) {
		for (int i = 0; i <= N; i++) {
			v.pb(Node(i));
		}
	}
	int find(int x) {
		if (v[x].p != x) {
			v[x].p = find(v[x].p);
		}
		return v[x].p;
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return;
		}

		if (v[x].sz > v[y].sz) {
			v[x].sz += v[y].sz;
			v[y].p = x;
		} else {
			v[y].sz += v[x].sz;
			v[x].p = y;
		}
	}
};

struct SegTree {
	struct Node {
		int l, r, v;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(3 * N) {
		// build(1, 1, N);
	}

	void build(int N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i].l = l;
		seg[i].r = r;
		if (l == r) {
			seg[i].v = val[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l(i), l, m);
		build(r(i), m + 1, r);
		seg[i].v = max(seg[l(i)].v, seg[r(i)].v);
	}

	int query(int i, int l, int r) {
		if (seg[i].l > r || seg[i].r < l) {
			return 0;
		}
		if (seg[i].l >= l && seg[i].r <= r) {
			return seg[i].v;
		}
		return max(query(l(i), l, r), query(r(i), l, r));
	}

	int query(int l, int r) {
		return query(1, l, r);
	}
} seg(MAXN);

void dfs(int i, int p) {
	par[i] = p;
	depth[i] = depth[p] + 1;
	size[i] = 1;
	for (int j = 0; j < mst[i].size(); j++) {
		if (mst[i][j].x == p) continue;

		dfs(mst[i][j].x, i);
		size[i] += size[mst[i][j].x];
	}
}

void HLD(int i, int c) {
	if (head[chainPos] == 0) {
		head[chainPos] = i;
	}
	chain[i] = chainPos;
	base[i] = basePos;
	val[basePos++] = c;

	int k = 0, cc = -1;
	for (int j = 0; j < mst[i].size(); j++) {
		if (mst[i][j].x == par[i]) continue;

		if (size[mst[i][j].x] > size[k]) {
			k = mst[i][j].x;
			cc = mst[i][j].y;
		}
	}

	if (k == 0) {
		return;
	}

	HLD(k, cc);

	for (int j = 0; j < mst[i].size(); j++) {
		if (mst[i][j].x != par[i] && mst[i][j].x != k) {
			chainPos++;
			HLD(mst[i][j].x, mst[i][j].y);
		}
	}
}

int LCA(int u, int v) {
	while (chain[u] != chain[v]) {
		if (depth[head[chain[u]]] < depth[head[chain[v]]]) {
			v = par[head[chain[v]]];
		} else {
			u = par[head[chain[u]]];
		}
	}
	return depth[u] < depth[v] ? u : v;
}

int queryUp(int u, int v) {
	int ret = -1;

	while (chain[u] != chain[v]) {
		ret = max(ret, seg.query(base[head[chain[u]]], base[u]));
		u = par[head[chain[u]]];
	}

	if (u == v) {
		return ret;
	}

	return max(ret, seg.query(base[v] + 1, base[u]));
}

int queryPath(int u, int v) {
	int lca = LCA(u, v);
	return max(queryUp(u, lca), queryUp(v, lca));
}

int main() {
	scan(N);
	scan(M);
	DisjointSet ds(N);

	for (int i = 0, a, b, c; i < M; ++i) {
		scan(a); scan(b); scan(c);
		e.pb(Edge(a, b, c));
	}
	sort(e.begin(), e.end());

	// Obtain MST
	for (int i = 0; i < M; i++) {
		if (ds.find(e[i].a) != ds.find(e[i].b)) {
			ds.merge(e[i].a, e[i].b);
			mst[e[i].a].pb(mp(e[i].b, e[i].c));
			mst[e[i].b].pb(mp(e[i].a, e[i].c));
			cost += e[i].c;
		} else {
			no.pb(e[i]);
		}
	}

	if (no.empty()) {
		printf("-1\n");
		return 0;
	}
	for (int i = 2; i <= N; ++i) {
		if (ds.find(1) != ds.find(i)) {
			printf("-1\n");
			return 0;
		}
	}

	// Build tree
	dfs(1, 1);
	chainPos = basePos = 0;
	HLD(1, -1);
	seg.build(basePos - 1);

	for (int i = 0; i < no.size(); i++) {
		if (no[i].c == queryPath(no[i].a, no[i].b)) continue;
		best = min(best, cost + no[i].c - queryPath(no[i].a, no[i].b));
	}

	printf("%lld\n", best == (ll) 1 << 60 ? -1 : best);
}
