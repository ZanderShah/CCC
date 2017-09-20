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

int T, Hd, Ad, Hk, Ak, B, D, dp[105][105][105][105];

int go(int d, int k, int bb, int dd, int c) {
	// cout << d << " " << k << " " << bb << " " << dd << endl;
	if (k <= 0) {
		return 0;
	}
	if (d <= 0) {
		return 1e6;
	}

	if (dp[d][k][bb][dd] != -1) {
		return dp[d][k][bb][dd];
	}

	int ret = 1e6;

	int add = Ad + bb * B;
	int akk = max(Ak - dd * D, 0);

	ret = min(ret, go(d - akk, k - add, bb, dd, 0) + 1);
	if (!c) {
		ret = min(ret, go(Hd - akk, k, bb, dd, 1) + 1);
	}
	if (B != 0 && add < k) {
		ret = min(ret, go(d - akk, k, bb + 1, dd, 0) + 1);
	}
	if (D != 0 && akk > 0) {
		akk = max(Ak - (dd + 1) * D, 0);
		ret = min(ret, go(d - akk, k, bb, dd + 1, 0) + 1);
	}

	return dp[d][k][bb][dd] = ret;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %d %d %d %d", &Hd, &Ad, &Hk, &Ak, &B, &D);

		memset(dp, -1, sizeof dp);

		go(Hd, Hk, 0, 0, 0);
		printf("Case #%d: ", t);
		if (dp[Hd][Hk][0][0] >= 1e6) {
			printf("IMPOSSIBLE\n");
		} else {
			printf("%d\n", dp[Hd][Hk][0][0]);
		}
	}
}
