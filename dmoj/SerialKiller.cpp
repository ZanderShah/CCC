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

struct SegTree {
	struct Node {
		int l, r;
        ll v;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(3 * N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i].l = l;
		seg[i].r = r;
        seg[i].v = 0;
		if (l == r) {
			// Initialize
			return;
		}
		int m = (l + r) >> 1;
		build(l(i), l, m);
		build(r(i), m + 1, r);
	}

	void update(int i, int l, int r, ll v) {
		if (seg[i].l > r || seg[i].r < l)
			return;
		if (seg[i].l >= l && seg[i].r <= r) {
			seg[i].v = max(seg[i].v, v);
			return;
		}
		update(l(i), l, r, v);
		update(r(i), l, r, v);
		// PushUp
		seg[i].v = max(seg[l(i)].v, seg[r(i)].v);
	}
	void update(int l, int r, ll v) {
		update(1, l, r, v);
	}

	ll query(int i, int l, int r) {
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
        if (r < l) return 0;
		return query(1, l, r);
	}
};

int N;
vector<pii> b;
vector<pii> xx, yy;

int main() {
    scanf("%d", &N);
	for (int i = 0, x, y; i < N; ++i) {
		scanf("%d %d", &x, &y);
		b.emplace_back(x, y);
	}
	sort(b.begin(), b.end());
	for (int i = 0; i < N; ++i) {
		xx.emplace_back(b[i].x, i);
		yy.emplace_back(b[i].y, i);
	}

	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	for (int i = 0, j = 1, k = 1; i < N; ++i) {
		if (i != 0 && b[i].x != b[i - 1].x) {
			++j;
		}
		if (i != 0 && b[i].y != b[i - 1].y) {
			++k;
		}
		b[i] = mp(j, k);
	}

    SegTree seg(N);

    for (int i = 0; i < N; ++i) {
        seg.update(W[i], W[i], seg.query(1, W[i] - 1) + V[i]);
    }

    printf("%lld\n", seg.query(1, N));
}
