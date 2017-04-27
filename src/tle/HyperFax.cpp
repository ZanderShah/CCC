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

int N;
int dist[2005], dp[2005][2005][2], ans;
pii h[2005];

int main () {
	scanf("%d", &N);

	int start = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &h[i].x, &h[i].y);
		if (h[i].x < 0) {
			start++;
		}
	}
	sort(h + 1, h + N + 1);

	for (int i = 1; i <= N; i++) {
		dist[i] = h[i].y + dist[i - 1];
	}

	memset(dp, -1, sizeof dp);
	dp[start][start][0] = dp[start][start][1] = 0;

	for (int i = start; i >= 1; i--) {
		for (int j = start; j <= N; j++) {
			// End up on left
			dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][0] - (h[i + 1].x - h[i].x));
			dp[i][j][0] = max(dp[i][j][0], dp[i + 1][j][1] - (h[j].x - h[i].x));
			if (dp[i][j][0] >= 0) {
				dp[i][j][0] += h[i].y;
			}
			// End up on right
			dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][1] - (h[j].x - h[j - 1].x));
			dp[i][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - (h[j].x - h[i].x));
			if (dp[i][j][1] >= 0) {
				dp[i][j][1] += h[j].y;
			}

			// printf("[%d, %d], %lld | %lld\n", i - start, j - start, dp[i][j][0], dp[i][j][1]);
		}
	}

	ans = -1;
	for (int i = start; i >= 1; i--) {
		for (int j = start; j <= N; j++) {
			if (dp[i][j][0] > 0 || dp[i][j][1] > 0) {
				ans = max(ans, dist[j] - dist[i - 1]);
			}
		}
	}
	printf("%d\n", ans);
}
