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

const int MAXN = 1e5 + 5;

int n, x[MAXN], h[MAXN], dp[MAXN][2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &h[i]);
	}
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < n; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + (h[i] < x[i] - x[i - 1]));
		dp[i][0] = max(dp[i][0], dp[i - 1][1] + (h[i] < x[i] - x[i - 1] - h[i - 1]));
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + (x[i] + h[i] < x[i + 1]);
	}
	printf("%d\n", max(dp[n - 1][0], dp[n - 1][1]) + 1);
}
