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

const int MOD = 1e9 + 7;

int N, K;
ll dp[35][905], per[35], inv[35];

ll invert(ll b) {
	ll ret = 1;
	for (int i = 0; i <= 30; i++) {
		if ((MOD - 2) >> i & 1) {
			ret = ret * b % MOD;
		}
		b = b * b % MOD;
	}
	return ret;
}

int main() {
	scanf("%d %d", &N, &K);

	per[0] = inv[0] = 1;
	for (int i = 1; i <= N; ++i) {
		per[i] = per[i - 1] * i % MOD;
		inv[i] = invert(per[i]);
	}

	dp[0][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; ++i) {
		for (int j = i; j <= K; ++j) {
			int n = i - 1;
			int k = j - i;

			for (int sz = 0; sz <= n; ++sz) {
				ll v = per[n] * inv[sz] % MOD * inv[n - sz] % MOD;
				for (int cst = sz; cst <= min(k, sz * (sz + 1) / 2); ++cst) {
					ll vv = dp[sz][cst] * dp[n - sz][k - cst] % MOD;
					dp[i][j] = (dp[i][j] + v * vv % MOD) % MOD;
				}
			}
		}
	}

	printf("%lld\n", dp[N][K]);
}
