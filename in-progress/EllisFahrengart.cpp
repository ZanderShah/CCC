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

int N, A[MAXN], Q, bit[MAXN], size;
ll inv = 0, ans[MAXN];
vector<int> val;
umii comp;

struct BIT {
	int N;
	vector<ll> bit;

	BIT(int N) : N(N), bit(N + 1) {
	}

	void update(int x, ll v) {
		if (x == 0) {
			return;
		}
		for (; x <= N; x += x & -x) {
			bit[x] += v;
		}
	}

	ll query(int x) {
		if (x == 0) {
			return 0;
		}
		ll ret = 0;
		for (; x; x -= x & -x) {
			ret += bit[x];
		}
		return ret;
	}
};

struct Query {
	int i, l, r, m;
	bool operator< (const Query &q) const {
		if (l / size == q.l / size) {
			return r < q.r;
		}
		return l < q.l;
	}
} q[MAXN];

int main() {
	scanf("%d", &N);
	BIT bit(N);
	size = sqrt(N);
	val.pb(-1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		val.pb(A[i]);
	}

	// Compress
	sort(val.begin(), val.end());
	for (int i = 1, j = 1; i < val.size(); i++) {
		while (i < val.size() && val[i] == val[i - 1]) {
			i++;
		}
		if (i < val.size()) {
			comp[val[i]] = j++;
		}
	}

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].i = i;
	}
	sort(q, q + Q);

	for (int i = 0, l = 0, r = 0; i < Q; i++) {
		while (l < q[i].l) {
			inv -= bit.query(comp[A[l]] - 1);
			bit.update(comp[A[l]], -1);
			l++;
		}
		while (l > q[i].l) {
			l--;
			inv += bit.query(comp[A[l]] - 1);
			bit.update(comp[A[l]], 1);
		}
		while (r < q[i].l) {
			r++;
			inv += r - l - bit.query(comp[A[r]]);
			bit.update(comp[A[r]], 1);
		}
		while (r > q[i].l) {
			inv -= r - l + 1 - bit.query(comp[A[r]]);
			bit.update(comp[A[r]], -1);
			r--;
		}

		ans[q[i].i] = inv;
	}

	for (int i = 0; i < Q; i++) {
		printf("%lld\n", ans[i]);
	}
}
