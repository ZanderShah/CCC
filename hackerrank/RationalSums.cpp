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

const int MOD = 1e9 + 7, MAXN = 5005;

int n, a[MAXN], b[MAXN];
ll A[MAXN], frac[MAXN + 1005];

ll p(ll x, ll e) {
	ll ret = 1;
	for (int i = 0; i < 30; i++) {
		if (e >> i & 1) {
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
	}
	return ret;
}

unordered_map<ll, ll> stupid;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}	
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 1; i <= 5000; i++) {
		stupid[i] = p(i, MOD - 2);
		stupid[MOD - i] = p(MOD - i, MOD - 2);
	}

	for (int i = 0; i < n; i++) {
		// RHS
		ll e = 1;
		for (int j = 0; j < n - 1; j++) {
			A[i] = (A[i] + b[j] * e % MOD) % MOD;
			e = e * (MOD - a[i]) % MOD;
		}
		// LHS
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			A[i] = A[i] * stupid[(a[j] - a[i] + MOD) % MOD] % MOD;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = a[j] + 1; i <= 5050; i++) {
			frac[i] = (frac[i] + A[j]) % MOD;
		}
	}

	ll sum = 0;
	for (int i = 1; i < 5050; i++) {
		if (frac[i]) {
			sum = (sum + frac[i] * p(i, MOD - 2) % MOD) % MOD;
		}
	}
	printf("%lld\n", sum);
}
