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

const int MAXN = 1e5;
const pii EMPTY_PII = mp(0, -1);

struct Node {
	pii l, r, m;
	bool lazy;
} seg[3 * MAXN];

const Node EMPTY_NODE = Node {EMPTY_PII, EMPTY_PII, EMPTY_PII};

inline pii _max(pii a, pii b) {
	if (a.y - a.x != b.y - b.x) {
		return a.y - a.x > b.y - b.x ? a : b;
	}
	return a.x < b.x ? a : b;
}

inline Node pushUp(Node l, Node r) {
	if (l.m == EMPTY_PII) {
		return r;
	}
	if (r.m == EMPTY_PII) {
		return l;
	}

	Node ret = Node {l.l, r.r, EMPTY_PII};

	if (l.l.y + 1 == r.l.x) {
		ret.l = mp(l.l.x, r.l.y);
	}
	if (r.r.x - 1 == l.r.y) {
		ret.r = mp(l.r.x, r.r.y);
	}

	ret.m = _max(ret.l, ret.r);
	ret.m = _max(ret.m, l.m);
	ret.m = _max(ret.m, r.m);
	if (l.r.y == r.l.x - 1) {
		ret.m = _max(ret.m, mp(l.r.x, r.l.y));
	}

	return ret;
}

void update(int i, int cL, int cR, int l, int r, int t) {
	if (seg[i].lazy) {
		if (seg[i >> 1].m == EMPTY_PII) {
			seg[i] = EMPTY_NODE;
		} else {
			seg[i].l = seg[i].m = seg[i].r = mp(cL, cR);
		}

		seg[i].lazy = 0;

		if (cL != cR) {
			seg[l(i)].lazy = 1;
			seg[r(i)].lazy = 1;
		}
	}

	if (cL > r || cR < l)
		return;

	if (cL >= l && cR <= r) {
		if (t == 0) {
			seg[i] = EMPTY_NODE;
		} else {
			seg[i].l = seg[i].m = seg[i].r = mp(cL, cR);
		}

		if (cL != cR) {
			seg[l(i)].lazy = seg[r(i)].lazy = 1;
		}

		return;
	}

	int m = (cL + cR) / 2;

	update(l(i), cL, m, l, r, t);
	update(r(i), m + 1, cR, l, r, t);

	seg[i] = pushUp(seg[l(i)], seg[r(i)]);
}

int N, Q, c, x, y;

int main() {
	scanf("%d %d", &N, &Q);

	update(1, 1, N, 1, N, 0);

	for (int i = 0; i < Q; i++) {
		scanf("%d", &c);
		if (c == 2) {
			update(1, 1, N, seg[1].m.x, seg[1].m.y, 0);
		} else {
			scanf("%d %d", &x, &y);
			update(1, 1, N, x, y, c);
			printf("%d\n", seg[1].m.y - seg[1].m.x + 1);
		}
	}
}
