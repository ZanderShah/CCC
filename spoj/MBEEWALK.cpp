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
#include <map>
#include <bitset>
#include <string>
#include <unordered_map>
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

const int DIR[6][2] = {{0, 1}, {-1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, 0}};
const int OFFSET = 25;

int t, n, dp[55][55][15];

int walk(int i, int j, int k) {
	if (k == n) {
		return i == OFFSET && j == OFFSET;
	}
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	int ret = 0;
	for (int d = 0; d < 6; d++) {
		ret += walk(i + DIR[d][0], j + DIR[d][1], k + 1);
	}
	return dp[i][j][k] = ret;
}

void solve() {
	scanf("%d", &n);
	memset(dp, -1, sizeof dp);
	printf("%d\n", walk(OFFSET, OFFSET, 0));
}

int main() {
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		solve();
	}
}
