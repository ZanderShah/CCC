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
#include <bitset>

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

inline ll mmod(ll a, ll b, ll m) {
	ll x = 0, y = a % m;
	for (int i = 0; i < 63; i++, y = y * 2 % m)
		if (b >> i & 1)
			x = (x + y) % m;
	return x;
}

inline ll bpow(ll a, ll b, ll m) {
	ll ret = 1;
	for (int i = 0; i < 63; i++, a = mmod(a, a, m))
		if (b >> i & 1)
			ret = mmod(ret, a, m);
	return ret;
}

bool isPrime(ll n) {
	if (n == 2) {
		return 1;
	}
	if (n < 2 || !(n & 1)) {
		return 0;
	}
	int t = 0;
	ll a, x, y, u = n - 1;
	while (!(u & 1)) {
		t++;
		u >>= 1;
	}
	for (int i = 0; i < 4; i++) {
		a = rand() % (n - 1) + 1;
		x = bpow(a, u, n);
		for (int j = 0; j < t; j++) {
			y = mmod(x, x, n);
			if (y == 1 && x != 1 && x != n - 1) {
				return 0;
			}
			x = y;
		}
		if (x != 1) {
			return 0;
		}
	}
	return 1;
}

ll f, l;
int megac;

void generate(ll v, ll e) {
	if (v + e * 7 < f || l < v) {
		return;
	}

	if (e == 0) {
		if (isPrime(v)) {
			megac++;
		}
		return;
	}

	if (v == 0) {
		generate(0, e / 10);
	}
	generate(v + 2 * e, e / 10);
	generate(v + 3 * e, e / 10);
	generate(v + 5 * e, e / 10);
	generate(v + 7 * e, e / 10);
}

int main() {
	scanf("%lld %lld", &f, &l);
	generate(0, 1e15);
	printf("%d\n", megac);
}
