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

int t, dp[2005][2005];
string a, b;

int edit(int i, int j) {
	if (i == a.length() || j == b.length()) {
		return max(a.length() - i, b.length() - j);
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ret = 5005;
	if (a[i] == b[j]) {
		ret = min(ret, edit(i + 1, j + 1));
	}
	ret = min(ret, edit(i + 1, j + 1) + 1);
	ret = min(ret, edit(i + 1, j) + 1);
	ret = min(ret, edit(i, j + 1) + 1);

	return dp[i][j] = ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		printf("%d\n", edit(0, 0));
	}
}
