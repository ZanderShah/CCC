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

inline int max(pii n) {
    return max(n.x, n.y);
}
inline int min(pii n) {
    return min(n.x, n.y);
}

const int MAXN = 200005;
int N, K;
pii C[MAXN], T[MAXN];
vector<int> t;
ll ans = 0;

struct BIT {
	int N;
	vector<int> bit;

	BIT(int N) : N(N), bit(N + 1) {
	}

	void update(int x, int v) {
		for (; x <= N; x += x & -x) {
			bit[x] += v;
		}
	}

	int query(int x) {
		int ret = 0;
		for (; x; x -= x & -x) {
			ret += bit[x];
		}
		return ret;
	}
};

struct SegTree {
	struct Node {
		int l, r, v;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(4 * N) {
		build(1, 1, N);
	}

	void build(int i, int l, int r) {
		seg[i].l = l;
		seg[i].r = r;
		if (l == r) {
            seg[i].v = T[l].y;
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
};

int main() {
    scanf("%d %d", &N, &K);
    BIT bit(K + 1);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &C[i].x, &C[i].y);
    }
    sort(C + 1, C + 1 + N, [](const pii &A, const pii &B){ 
        return max(A) < max(B); 
    });

    for (int i = 1; i <= K; i++) {
        scanf("%d", &T[i].x);
        T[i].y = i;
        bit.update(i, 1);
    }
    sort(T + 1, T + 1 + K);
    
    t.pb(0);
    for (int i = 1; i <= K; i++) {
        t.pb(T[i].x);    
    }
    t.pb(1 << 30);
    SegTree seg(t.size());

    // BIT -> Number of definite flips
    for (int i = 1, j = 1; i <= N; i++) {
        while (j <= K && T[j].x < max(C[i])) {
            bit.update(T[j].y, -1);
            j++;
        }

        int l = lower_bound(t.begin(), t.end(), min(C[i])) - t.begin();
        int r = lower_bound(t.begin(), t.end(), max(C[i])) - t.begin();

        int k = seg.query(l, r - 1);
        bool f = (bit.query(K) - bit.query(k)) & 1;

        if (k == 0) {
            if (f) {
                ans += C[i].y;
            } else {
                ans += C[i].x;
            }
        } else {
            if (f) {
                ans += min(C[i]);
            } else {
                ans += max(C[i]);
            }
        }
    }
    printf("%lld\n", ans);
}
