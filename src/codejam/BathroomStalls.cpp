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

int T;
ll N, K, a, b, c, x;

int main() {
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++) {
		scanf("%lld %lld", &N, &K);
		a = b = N;

		for (ll i = 1; K > 0; i <<= 1) {
			if (i < K) {
				a = a / 2;
				b = (b - 1) / 2;
			} else if (a != b) {
				// Sum of row
				c = N + 1 - i;
				// Number of larger value
				x = (c - b * i) / (a - b);

				if (x < K) {
					a = b;
				}
			}

			K -= i;
		}

		printf("Case #%d: %lld %lld\n", rr, a / 2, (a - 1) / 2);
	}
}
