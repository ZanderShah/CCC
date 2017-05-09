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

struct SegTree {
	struct Node {
		int l, r;
		ll v, lazy;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(5 * N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i] = Node {l, r, 0, 0};
		if (l == r) {
			return;
		}
		int m = (l + r) >> 1;
		build(l(i), l, m);
		build(r(i), m + 1, r);
	}

	void update(int i, int l, int r, ll v) {
		// Lazy Propogation
		if (seg[i].lazy != 0 && seg[i].l != seg[i].r) {
			seg[l(i)].v += seg[i].lazy;
			seg[l(i)].lazy += seg[i].lazy;
			seg[r(i)].v += seg[i].lazy;
			seg[r(i)].lazy += seg[i].lazy;
			seg[i].lazy = 0;
		}

		if (seg[i].l > r || seg[i].r < l) {
			return;
		}
		if (seg[i].l >= l && seg[i].r <= r) {
			// Update value and lazy
			seg[i].v += v;
			seg[i].lazy += v;
			return;
		}
		update(l(i), l, r, v);
		update(r(i), l, r, v);
		// PushUp
		seg[i].v = max(seg[l(i)].v, seg[r(i)].v);
	}
	void update(int l, int r, ll v) {
		update(1, max(1, l + 1), r + 1, v);
	}

	ll query(int i, int l, int r) {
		if (r < l) {
			return 0;
		}
		// Lazy Propogation
		if (seg[i].lazy != 0 && seg[i].l != seg[i].r) {
			seg[l(i)].v += seg[i].lazy;
			seg[l(i)].lazy += seg[i].lazy;
			seg[r(i)].v += seg[i].lazy;
			seg[r(i)].lazy += seg[i].lazy;
			seg[i].lazy = 0;
		}

		if (seg[i].l > r || seg[i].r < l) {
			// Empty
			return 0;
		}
		if (seg[i].l >= l && seg[i].r <= r) {
			// Value
			return seg[i].v;
		}
		// PushUp
		return max(query(l(i), l, r), query(r(i), l, r));
	}
	ll query(int l, int r) {
		if (r < l) {
			swap(l, r);
		}
		if (l >= N) {
			return 0;
		}
		return query(1, max(1, l + 1), min(N, r + 1));
	}
};

int main() {
	int N, K, Q;
	scanf("%d %d %d", &N, &K, &Q);
	SegTree seg(N);

	for (int i = 0, c, p, v, l, r; i < Q; i++) {
		scanf("%d", &c);
		if (c == 0) {
			scanf("%d %d", &p, &v);
			seg.update(p - K + 1, p, v);
		} else {
			scanf("%d %d", &l, &r);
			printf("%lld\n", seg.query(l, r));
		}
	}
}
