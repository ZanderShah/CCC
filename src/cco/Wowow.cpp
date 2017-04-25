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

const int MAXN = 1e6 + 5;

char C[MAXN];
int N, X[MAXN], K[MAXN], R[MAXN], name[MAXN], ranked[MAXN], total;
priority_queue<int> pq;
umii comp;
BIT bit(MAXN);

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c", &C[i]);
		if ('Q' == C[i]) {
			scanf("%d", &K[i]);
		} else {
			scanf("%d %d", &X[i], &R[i]);
			pq.push(R[i]);
		}
	}

	total = pq.size();
	// Reverse ordering
	for (int i = 1; !pq.empty(); ++i) {
		comp[pq.top()] = i;
		pq.pop();
	}

	for (int i = 0; i < N; ++i) {
		if (C[i] == 'M') {
			bit.update(ranked[X[i]], -1);
		}
		if (C[i] == 'N' || C[i] == 'M') {
			bit.update(comp[R[i]], 1);
			name[comp[R[i]]] = X[i];
			ranked[X[i]] = comp[R[i]];
		} else if (C[i] == 'Q') {
			int lo = 1, hi = total, mid = (lo + hi) >> 1;
			while (lo <= hi) {
				if (bit.query(mid) < K[i]) {
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
				mid = (lo + hi) >> 1;
			}
			printf("%d\n", name[lo]);
		}
	}
}
