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

int N, K, a[200005], L = 0;

struct SegTree {
	struct Node {
		int l, r, v, lazy;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(3 * N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i].l = l;
		seg[i].r = r;
		if (l == r) {
            seg[i].v = 2000000001;
            if (l + K - 1 <= N) {
                seg[i].v = a[l + K - 1] - a[l];
            }
			return;
		}
		int m = (l + r) >> 1;
		build(l(i), l, m);
        build(r(i), m + 1, r);
        seg[i].v = min(seg[l(i)].v, seg[r(i)].v);
	}

	int query(int i, int l, int r) {
		if (seg[i].l > r || seg[i].r < l) {
			return 2000000001;
		}
		if (seg[i].l >= l && seg[i].r <= r) {
			return seg[i].v;
		}
		return min(query(l(i), l, r), query(r(i), l, r));
	}
	int query(int l, int r) {
		return query(1, l, r);
	}
};

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + N + 1);
    SegTree seg(N);
    for (int i = 1; i <= N; i++) {
        L = max(L, seg.query(max(i - K + 1, 1), min(i, N - K + 1)));
    }
    printf("%d\n", L);
}
