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

const int OFFSET = 25;

int d, n, k, dp[50][50];
bool lf[40];

int go(int i, int j) {
	if (j < OFFSET) {
		return 0;
	}
	if (2 * n < i) {
		return j == OFFSET;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	return dp[i][j] = go(i + 1, j + 1) + (lf[i] ? 0 : go(i + 1, j - 1));
}

int main() {
	scanf("%d", &d);
	for (int t = 0; t < d; t++) {
		scanf("%d %d", &n, &k);

		memset(lf, 0, sizeof lf);
		for (int i = 0, x; i < k; i++) {
			scanf("%d", &x);
			lf[x] = 1;
		}
		memset(dp, -1, sizeof dp);

		printf("%d\n", go(1, OFFSET));
	}
}
