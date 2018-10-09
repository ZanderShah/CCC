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

const int MAXN = 1e5 + 5;
int N, W[MAXN], V[MAXN];

int main() {
    scanf("%d", &N);

    vector<pii> c(N + 1);
    c[0].x = -1;
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &W[i]);
        c[i] = mp(W[i], i);
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &V[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 1, j = 1; i <= N; ++i) {
        if (i != 1 && c[i].x != c[i - 1].x) {
            ++j;
        }
        W[c[i].y] = j;
    }

    SegTree seg(N);
    for (int i = N; i >= 1; --i) {
        seg.update(W[i], W[i], seg.query(1, W[i] - 1) + V[i]);
    }

    printf("%lld\n", seg.query(1, N));
}
