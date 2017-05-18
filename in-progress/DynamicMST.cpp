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
		int p, r;
		Node(int p) : p(p) {
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
	bool merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return 0;
		}

		if (v[x].r < v[y].r) {
			v[x].p = y;
		}else if (v[x].r > v[y].r) {
			v[y].p = x;
		}else {
			v[y].p = x;
			v[x].r++;
		}

		return 1;
	}
};

struct Edge {
	int x, y, w, i;
	bool operator< (const Edge &e) const {
		return w < e.w;
	}
};

const int MAXN = 50005;

int N, M, Q, ind[MAXN];
vector<Edge> edges;

ll getMST(int k, int d) {
	vector<Edge> hold;

	ll ret = 0;
	DisjointSet ds(N);

	for (int i = 0; i <= M; i++) {
		if (edges[i].i == k) continue;

		if (d < edges[i].w) {
			edges[ind[k]].w = d;

			if (ds.merge(edges[ind[k]].x, edges[ind[k]].y)) {
				ret += edges[ind[k]].w;
			}

			hold.pb(edges[ind[k]]);

			d = 50000005;
		}

		if (ds.merge(edges[i].x, edges[i].y)) {
			ret += edges[i].w;
		}

		hold.pb(edges[i]);
	}

	swap(edges, hold);
	for (int i = 0; i <= M; i++) {
		ind[edges[i].i] = i;
	}

	return ret;
}

int main() {
	scan(N); scan(M); scan(Q);

	for (int i = 1, x, y, w; i <= M; i++) {
		scan(x); scan(y); scan(w);
		edges.pb(Edge {x, y, w, i});
	}
	edges.pb(Edge {0, 0, 50000005, 0});

	sort(edges.begin(), edges.end());
	for (int i = 0; i <= M; i++) {
		ind[edges[i].i] = i;
	}

	for (int i = 0, k, d; i < Q; i++) {
		scan(k); scan(d);

		printf("%lld\n", getMST(k, d));
	}
}
