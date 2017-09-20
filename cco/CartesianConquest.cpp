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

int N, M, j = 0;
unordered_map<int, unordered_map<int, pii> > dp;

pii go(int n, int m) {
	if (n == 0 || m == 0) {
		return mp(0, 0);
	}
	if (n < m) {
		swap(n, m);
	}

	if (dp[n].find(m) != dp[n].end()) {
		return dp[n][m];
	}

	pii ret = mp(1e9, 0);

	int d = 1 << 30;

	while (d > 1) {
		if (n - 1ll * d * m >= 0) {
			pii g = go(n - d * m, m);
			ret.x = min(ret.x, g.x + d / 2);
			ret.y = max(ret.y, g.y + d / 2 + (m % 2 ? 0 : 3 * d / 2));
			if (n > 2 * d * m) {
				return dp[n][m] = ret;
			}
		}
		d >>= 1;
	}

	if (n % 2 == 0 && m - n / 2 >= 0) {
		pii g = go(n, m - n / 2);
		ret.x = min(ret.x, g.x + 1);
		ret.y = max(ret.y, g.y + 1);
	}
	if (n < 4 * m && m % 2 == 0) {
		pii g = go(n - m / 2, m);
		ret.x = min(ret.x, g.x + 1);
		ret.y = max(ret.y, g.y + 1);
	}

	return dp[n][m] = ret;
}

int main() {
	scanf("%d %d", &N, &M);
	if (N < M) {
		swap(N, M);
	}
	go(N, M);
	printf("%d %d\n", dp[N][M].x, dp[N][M].y);
}
