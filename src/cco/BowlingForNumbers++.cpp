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

int t, n, k, w, v[10505], dp[505][10505];

int bowl(int i, int j) {
	if (i > k || j > n)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	int ret = max(bowl(i, j + 1), bowl(i + 1, j + w) + v[j + w - 1] - v[j - 1]);
	if (j == 1) {
		for (int l = 1; l < w; l++)
			ret = max(ret, bowl(i + 1, j + l) + v[j + l - 1] - v[j - 1]);
	}
	if (i + 1 <= k)
		for (int l = 1; l < w; l++)
			ret = max(ret, bowl(i + 2, j + w + l) + v[j + w + l - 1] - v[j - 1]);
	return dp[i][j] = ret;
}

int main() {
	scanf("%d", &t);
	v[0] = 0;
	for (int r = 0; r < t; r++) {
		scanf("%d %d %d", &n, &k, &w);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
			v[i] += v[i - 1];
		}
		for (int i = n + 1; i <= n + 2 * w; i++)
			v[i] = v[n];
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = -1;
		printf("%d\n", bowl(1, 1));
	}
}
