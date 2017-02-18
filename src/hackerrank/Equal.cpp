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
#include <cstdio>
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
typedef unordered_map<int, int> umii;

int T, N, x[10005], m, dp[1005];

int go(int x) {
	if (x < m) {
		return 1e9;
	}
	if (x == m) {
		return 0;
	}
	if (dp[x + 5] != -1) {
		return dp[x + 5];
	}
	int ret = go(x - 1) + 1;
	ret = min(ret, go(x - 2) + 1);
	ret = min(ret, go(x - 5) + 1);
	return dp[x + 5] = ret;
}

int main() {
	scanf("%d", &T);
	for (int r = 0; r < T; r++) {
		scanf("%d", &N);

		m = 1005;
		for (int i = 0; i < N; i++) {
			scanf("%d", &x[i]);
			m = min(m, x[i]);
		}

		int bans = 1e9;
		for (int j = 0; j < 5; j++) {
			memset(dp, -1, sizeof dp);
			int ans = 0;
			for (int i = 0; i < N; i++) {
				ans += go(x[i]);
			}
			m--;
			bans = min(bans, ans);
		}
		printf("%d\n", bans);
	}
}
