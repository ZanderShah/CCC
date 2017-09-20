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

const int MAXN = 150005, MAGIC = 505;

int N, M, Q, L[MAXN], A[MAXN], rot[MAXN];
vector<int> lines[MAXN], big, sum[MAXN];
bool small[MAXN];
BIT bit(MAXN);

void updateSmall(int x) {
	for (int i = 0; i < lines[x].size(); i++) {
		bit.update(lines[x][i], -A[lines[x][(i + rot[x]) % lines[x].size()]]);
	}
	rot[x] = (rot[x] + lines[x].size() - 1) % lines[x].size();
	for (int i = 0; i < lines[x].size(); i++) {
		bit.update(lines[x][i], A[lines[x][(i + rot[x]) % lines[x].size()]]);
	}
}
void updateLarge(int x) {
	rot[x] = (rot[x] + lines[x].size() - 1) % lines[x].size();
}
int querySmall(int l, int r) {
	return bit.query(r) - bit.query(l - 1);
}
int queryLine(int x, int l, int r) {
	int ret = 0;

	int lo = 0, hi = lines[x].size() - 1, m = (lo + hi) >> 1;

	while (lo <= hi) {
		if (lines[x][m] <= r) {
			lo = m + 1;
		} else {
			hi = m - 1;
		}
		m = (lo + hi) >> 1;
	}

	ret += sum[x][lo + rot[x]];

	lo = 0;
	hi = lines[x].size() - 1;
	m = (lo + hi) >> 1;

	while (lo <= hi) {
		if (lines[x][m] < l) {
			lo = m + 1;
		} else {
			hi = m - 1;
		}
		m = (lo + hi) >> 1;
	}

	ret -= sum[x][lo + rot[x]];

	return ret;
}
int queryLarge(int l, int r) {
	int ret = 0;
	for (int i = 0; i < big.size(); i++) {
		ret += queryLine(big[i], l, r);
	}
	return ret;
}

int main() {
	scanf("%d %d %d", &N, &M, &Q);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &L[i]);
		lines[L[i]].pb(i);
	}
	for (int i = 1; i <= M; i++) {
		small[i] = lines[i].size() <= MAGIC;
		rot[i] = 0;
		if (small[i] == 0) {
			big.pb(i);
			sum[i].pb(0);
		}
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		if (small[L[i]]) {
			bit.update(i, A[i]);
		}
	}
	// Prefix sum for big lines
	for (int i = 0; i < big.size(); i++) {
		for (int r = 1; r <= 2; r++) {
			for (int j = 0; j < lines[big[i]].size(); j++) {
				sum[big[i]].pb(sum[big[i]].back() + A[lines[big[i]][j]]);
			}
		}
	}

	for (int i = 1, c, l, r, x; i <= Q; i++) {
		scanf("%d", &c);
		if (c == 1) {
			scanf("%d %d", &l, &r);
			printf("%d\n", querySmall(l, r) + queryLarge(l, r));
		} else {
			scanf("%d", &x);
			if (small[x]) {
				updateSmall(x);
			} else {
				updateLarge(x);
			}
		}
	}
}
