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
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;

int n, a[10005];
double dp[10005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
		if (i >= 2)
			dp[i] = min(dp[i], dp[i - 2] + a[i - 1] + a[i] - min(a[i - 1], a[i]) / 2.0);
		if (i >= 3)
			dp[i] = min(dp[i], dp[i - 3] + a[i - 2] + a[i - 1] + a[i] - min(a[i - 2], min(a[i - 1], a[i])));
	}
	printf("%.1f", dp[n]);
}