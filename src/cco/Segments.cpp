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

#define pb push_back
#define mp make_pair
#define l(x) x << 1
#define r(x) x << 1 | 1
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
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

const int MAXN = 20005;
int n, dp[MAXN][2];
pii seg[MAXN];

int main() {
	scan(n);
	for (int i = 1; i <= n; i++) {
		scan(seg[i].x);
		scan(seg[i].y);
	}
	dp[1][1] = seg[1].y - 1;
	dp[1][0] = dp[1][1] + seg[1].y - seg[1].x;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + abs(seg[i].y - seg[i - 1].x),
				dp[i - 1][1] + abs(seg[i].y - seg[i - 1].y)) + 1 + seg[i].y
				- seg[i].x;
		dp[i][1] = min(dp[i - 1][0] + abs(seg[i].x - seg[i - 1].x),
				dp[i - 1][1] + abs(seg[i].x - seg[i - 1].y)) + 1 + seg[i].y
				- seg[i].x;
	}
	printf("%d\n", min(dp[n][0] + n - seg[n].x, dp[n][1] + n - seg[n].y));
}
