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

int N, A[MAXN], Q, bit[MAXN];
ll ans[MAXN];

void update(int x, int v) {
	for (; x < MAXN; x += x & -x) {
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

struct Query {
	int i, l, r, m;
	bool operator< (const Query &q) const {
		if (l == q.l) {
			return r < q.r;
		}
		return l < q.l;
	}
} q[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].i = i;
	}
	sort(q, q + Q);

	int l = 1, r = 1;
	ll s = 0;

	for (int i = 0; i < Q; i++) {
		while (l < q[i].l) {
			s -= query(A[l] - 1);
			update(A[l], -1);
			l++;
		}
		while (r < q[i].r) {
			s += query(A[r]);
			update(A[r], 1);
			r++;
		}
		while (r > q[i].r) {
			s -= query(A[r]);
			update(A[r], -1);
			r--;
		}

		ans[q[i].i] = s;
	}

	for (int i = 0; i < Q; i++) {
		printf("%lld\n", ans[i]);
	}
}
