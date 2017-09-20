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

int t, n, m, dp[205][205][2];
char M[205][205];

int go(int i, int j, bool r) {
	if (i < 0 || i >= n || j < 0 || j >= m) {
		return 0;
	}
	if (dp[i][j][r] != -1) {
		return dp[i][j][r];
	}
	if (M[i][j] == '#') {
		return 0;
	}

	int ret = 0;

	if (r) {
		ret = max(ret, go(i, j + 1, 1));
		ret = max(ret, go(i + 1, j, 0));
	} else {
		ret = max(ret, go(i, j - 1, 0));
		ret = max(ret, go(i + 1, j, 1));
	}
	return dp[i][j][r] = ret + (M[i][j] == 'T');
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf(" %s", M[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", go(0, 0, 1));
}

int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		solve();
	}
}
