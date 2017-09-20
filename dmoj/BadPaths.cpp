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
#include <unordered_set>
#include <map>
#include <bitset>
#include <stdio.h>

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
typedef unordered_map<int, int> umii;

const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7, TWO = 500000004;
int N;
ll f[MAXN], x[MAXN], d[MAXN], M;

ll bpow(ll x, ll p) {
	ll ret = 1;
	for (int i = 0; i < 32; i++, x = x * x % MOD) {
		if (p >> i & 1) {
			ret = ret * x % MOD;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &x[i]);
		M = max(M, x[i]);
	}
	f[0] = d[0] = 1;
	for (ll i = 1; i <= M; i++) {
		f[i] = f[i - 1] * i % MOD;
		d[i] = (d[i - 1] + bpow(f[i], MOD - 2)) % MOD;
	}
	for (int i = 0; i < N; i++) {
		ll a = f[x[i]] * d[x[i]] % MOD;
		ll b = x[i] * (x[i] - 1) % MOD;
		printf("%lld\n", (a - (x[i] + 1) - b + MOD) * TWO % MOD);
	}
}
