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

ll R, C, K;
ll r, c, fence = 0;

int main() {
	scanf("%lld %lld %lld", &R, &C, &K);
	r = ceil(sqrt(K));
	c = (K + r - 1) / r;
	fence = 2 * (c + r);
	if (r > R) {
		r = R;
		c = (K + r - 1) / r;
//		while (r * c < K)
//			c++;
		fence = 2 * (c + r);
	}
	if (c > C) {
		c = C;
		r = (K + c - 1) / c;
//		while (r * c < K)
//			r++;
		fence = 2 * (c + r);
	}
	printf("%lld\n", fence);

}
