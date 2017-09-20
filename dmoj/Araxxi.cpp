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
int N, M, a[MAXN], c[MAXN], dp[MAXN][2], last[MAXN];
vector<int> cc[MAXN];

int next(int i, int j) {
	int lo = 0, hi = cc[j].size() - 1, mid = (lo + hi) >> 1;
	while (lo <= hi) {
		if (cc[j][mid] <= i) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
		mid = (lo + hi) >> 1;
	}

	if (lo < cc[j].size()) {
		return cc[j][lo];
	}
	return 1 << 30;
}

int fight(int i, bool j) {
	if (N < i) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int ret = 0;

	if (j == 0) {
		ret = max(ret, fight(i + 1, 0));
	}
	ret = max(ret, fight(i + 1 + c[a[i]], 0) + 1);
	ret = max(ret, fight(next(i, a[i]), 1) + 1);

	return dp[i][j] = ret;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		cc[a[i]].pb(i);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &c[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%d\n", fight(1, 0));
}
