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
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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

int a, b;
ll f;

bool valid(ll g, ll x) {
	f = 0;
	for (ll m = 5; m <= g; m *= 5)
		f += g / m;
	return f <= x;
}

ll count(int x) {
	if (x < 0)
		return 0;
	ll l = 0, u = 1e10;
	while (l <= u)
		if (valid((l + u) / 2, x))
			l = (l + u) / 2 + 1;
		else
			u = (l + u) / 2 - 1;
	return u;
}

int main() {
	scanf("%d %d", &a, &b);
	printf("%lld", count(b) - count(a - 1));
}
