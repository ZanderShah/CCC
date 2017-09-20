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

ll n, k;

set<ll> f;

bool testPrint(ll d, ll s) {
	vector<ll> c;

	for (ll i = 1; i < k; i++) {
		c.pb(i * d);
		s -= i * d;
		if (s / d < k) {
			return 0;
		}
	}

	for (ll i = 0; i < c.size(); i++) {
		printf("%lld ", c[i]);
	}
	printf("%lld\n", s);
	return 1;
}

int main() {
	scanf("%lld %lld", &n, &k);

	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			f.insert(i);
			f.insert(n / i);
		}
	}

	for (auto it = f.rbegin(); it != f.rend(); ++it) {
		// Sum of coefficients
		if (testPrint(*it, n)) {
			return 0;
		}
	}

	printf("-1\n");
}
