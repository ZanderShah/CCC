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

struct SegmentTree {
	struct Node {
		int l, r, v, lazy;
	};

	int N;
	vector<Node> seg;

	SegmentTree(int N) : N(N), seg(4 * N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i].l = l;
		seg[i].r = r;
		if (l == r) {
			// Initialize
			return;
		}
		int m = (l + r) / 2;
		build(l(i), l, m);
		build(r(i), m + 1, r);
	}

	void update(int i, int l, int r, int v) {
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
	void update(int l, int r, int v) {
		update(1, l, r, v);
	}

	int query(int i, int l, int r) {
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
	int query(int l, int r) {
		return query(1, l, r);
	}
};

struct BIT {
	int N;
	vector<int> bit1, bit2;

	BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) {
	}

	void update(vector<int> &bit, int x, int v) {
		for (; x <= N; x += x & -x) {
			bit[x] += v;
		}
	}

	void update(int x, int y, int v) {
		update(bit1, x, v);
		update(bit1, y + 1, -v);
		update(bit2, x, v * (x - 1));
		update(bit2, y + 1, -v * y);
	}

	int query(vector<int> &bit, int x) {
		int ret = 0;
		for (; x; x -= x & -x) {
			ret += bit[x];
		}
		return ret;
	}

	int query(int x) {
		return query(bit1, x) * x - query(bit2, x);
	}

	int query(int x, int y) {
		return query(y) - query(x - 1);
	}
};

const int MAXN = 1e5 + 5;

int T, N;
pii s[MAXN];

int main() {
	scan(T);
	for (int t = 1; t <= T; ++t) {
		scan(N);
		int ans = 0;

		vector<int> x = {-1};
		for (int i = 0; i < N; ++i) {
			scan(s[i].x); scan(s[i].y);
			x.pb(s[i].x);
			x.pb(s[i].y);
		}
		sort(s, s + N);
		sort(x.begin(), x.end());

		umii c;
		int size = 0;
		for (int i = 1; i < x.size(); i++) {
			while (i < x.size() && x[i] == x[i - 1]) {
				i++;
			}
			if (i < x.size()) {
				c[x[i]] = ++size;
			}
		}

		SegmentTree seg(size);
		for (int i = 0; i < N; ++i) {
			seg.update(c[s[i].x], c[s[i].y], 1);
		}

		BIT bit(size);
		// Sweep through all possible left cuts
		for (int i = 1, j = 0; i <= size; ++i) {
			while (j < N && c[s[j].x] <= i) {
				seg.update(c[s[j].x], c[s[j].y], -1);
				bit.update(c[s[j].x], c[s[j].y], 1);
				j++;
			}
			// printf("%d %d %d\n", i, bit.query(i), seg.query(i + 1, size));
			ans = max(ans, bit.query(i, i) + seg.query(i + 1, size));
		}

		printf("Case %d: %d\n", t, ans);
	}
}
