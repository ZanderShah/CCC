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

const int MAXN = 4001, MOD = 1e9 + 7;
int N, M;
ll X[MAXN], F[MAXN], C[MAXN][MAXN], D[MAXN][MAXN], dp[MAXN][21];

inline ll c(int l, int r, int j) {
	return C[r][j] - C[l - 1][j];
}

ll f(int L, int R) {
	ll ret = c(L, R, L);

	int l = L + 1, r = R, m = (l + r) >> 1;
	while (l <= r) {
		if (c(L, R, m) < c(L, R, m - 1)) {
			l = m + 1;
		} else {
			r = m - 1;
		}
		m = (l + r) >> 1;
	}

	return min(ret, c(L, R, r));
}

void solve() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%lld %lld", &X[i], &F[i]);
	}

	memset(C, 0, sizeof C);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			C[i][j] = F[i] * abs(X[i] - X[j]) + C[i - 1][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			D[i][j] = f(i, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i <= j) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = 1ll << 60;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		dp[i][1] = f(1, i);
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= M; j++) {
			for (int k = 2; k <= i; k++) {
				dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + D[k][i]);
			}
		}
	}

	printf("%lld\n", dp[N][M] % MOD);
}

int main() {
	for (int i = 0; i < 10; i++) {
		solve();
	}
}
