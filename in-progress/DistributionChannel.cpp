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


struct Edge {
	int a, b, c;
	Edge(int a, int b, int c) : a(a), b(b), c(c) {
	}
	bool operator< (const Edge e) const {
		return c < e.c;
	}
};

int N, M;
ll cost = 0, best = (ll) 1 << 60;
vector<Edge> e, no;
vector<pii> mst[50005];
bool vis[50005];

void tour(int i) {
	vis[i] = 1;
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
}
