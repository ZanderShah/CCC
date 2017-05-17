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

const int MAXN = 1e5 + 5;
const ll INF = 1e15;

int N, a[MAXN], Q;
char c;

struct Node {
	ll lv, rv, mv, sum;
} seg[3 * MAXN];

Node pushUp(Node l, Node r) {
	if (l.sum == -INF) {
		return r;
	}
	if (r.sum == -INF) {
		return l;
	}
	Node ret;

	ret.sum = l.sum + r.sum;
	ret.lv = max(l.lv, l.sum + r.lv);
	ret.rv = max(r.rv, r.sum + l.rv);

	ret.mv = max(ret.rv, ret.lv);
	ret.mv = max(ret.mv, ret.sum);
	ret.mv = max(ret.mv, l.rv + r.lv);
	ret.mv = max(ret.mv, l.mv);
	ret.mv = max(ret.mv, r.mv);

	return ret;
}

void update(int i, int l, int r, ll x) {
	if (l > x || r < x) {
		return;
	}
	if (l == r) {
		seg[i].sum = seg[i].lv = seg[i].rv = seg[i].mv = a[l];
		return;
	}
	int m = (l + r) / 2;
	update(l(i), l, m, x);
	update(r(i), m + 1, r, x);
	seg[i] = pushUp(seg[l(i)], seg[r(i)]);
}

Node query(int i, int cL, int cR, int l, int r) {
	if (cL > r || cR < l) {
		return Node {-INF, -INF, -INF, -INF};
	}

	if (cL >= l && cR <= r) {
		return seg[i];
	}

	int m = (cL + cR) / 2;
	return pushUp(query(l(i), cL, m, l, r), query(r(i), m + 1, cR, l, r));
}

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		update(1, 1, N, i);
	}

	for (int i = 0, x, y; i < Q; i++) {
		scanf(" %c %d %d", &c, &x, &y);
		if (c == 'S') {
			a[x] = y;
			update(1, 1, N, x);
		} else {
			printf("%lld\n", query(1, 1, N, x, y).mv);
		}
	}
}
