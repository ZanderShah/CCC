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

const int MAXN = 105;

int N, dp[MAXN][MAXN][2], total = 0;
bool odd[MAXN];

// Max odd numbers that Ivana can pick
int play(int i, int j, bool k) {
	if (i == j) {
		return odd[i] & k;
	}
	if (dp[i][j][k] != -1) {
		return dp[i][j][k];
	}
	// Either pick the left or right number
	int l = (i + N - 1) % N, r = (j + 1) % N;

	if (k) {
		return dp[i][j][k] = max(play(l, j, 0) + odd[i], play(i, r, 0) + odd[j]);
	} else {
		return dp[i][j][k] = min(play(l, j, 1), play(i, r, 1));
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++) {
		scanf("%d", &x);
		odd[i] = x & 1;
		total += odd[i];
	}
	memset(dp, -1, sizeof dp);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += play((i + N - 1) % N, (i + 1) % N, 0) + odd[i] > total / 2;
	}
	printf("%d\n", ans);
}
