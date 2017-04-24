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

int N, K, a[MAXN], Q, l, r, best[MAXN], lo, hi, mid;
pii ans;

struct Node {
	int l, r, mini, maxi;
} seg[3 * MAXN];

// struct Query {
//      int i, l, r;
//      bool operator< (const Query &q) const {
//              if (l == q.l) {
//                      return r < q.r;
//              }
//              return l < q.l;
//      }
// } q[MAXN];

void build(int i, int l, int r) {
	seg[i].l = l;
	seg[i].r = r;
	if (l == r) {
		seg[i].mini = seg[i].maxi = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(l(i), l, m);
	build(r(i), m + 1, r);
	seg[i].mini = min(seg[l(i)].mini, seg[r(i)].mini);
	seg[i].maxi = max(seg[l(i)].maxi, seg[r(i)].maxi);
}

int minq(int i, int l, int r) {
	if (seg[i].l > r || seg[i].r < l) {
		return 1 << 30;
	}
	if (seg[i].l >= l && seg[i].r <= r) {
		return seg[i].mini;
	}
	return min(minq(l(i), l, r), minq(r(i), l, r));
}

int maxq(int i, int l, int r) {
	if (seg[i].l > r || seg[i].r < l) {
		return -1;
	}
	if (seg[i].l >= l && seg[i].r <= r) {
		return seg[i].maxi;
	}
	return max(maxq(l(i), l, r), maxq(r(i), l, r));
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}
	build(1, 1, N);

	// Precomute ending point for any l
	for (int i = 1; i <= N; i++) {
		lo = i;
		hi = N;
		mid = (lo + hi) >> 1;

		while (lo <= hi) {
			if (maxq(1, i, mid) - minq(1, i, mid) <= K) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
			mid = (lo + hi) >> 1;
		}

		best[i] = hi;
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &l, &r);
		ans = mp(l, min(best[l], r));

		for (int j = l; j <= r && ans.y != r; j++) {
			if (min(best[j], r) - j > ans.y - ans.x) {
				ans = mp(j, min(best[j], r));
			}
		}

		printf("%d %d\n", ans.x, ans.y);
	}
}
