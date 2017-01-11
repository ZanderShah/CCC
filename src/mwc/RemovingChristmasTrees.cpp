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
#include <stdio.h>

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

int N, dp[1005][1005], label[1005];
struct {
	int v, l, r;
} n[1005];

int go(int l, int r) {
	if (l > r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int ret = go(l + 1, r) + 1;
	for (int j = n[l].r; j <= r && j; j = n[j].r) {
		ret = min(ret, go(l + 1, j - 1) + go(j, r));
	}
	return dp[l][r] = ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &n[i].v);
		n[i].l = label[n[i].v];
		n[label[n[i].v]].r = i;
		label[n[i].v] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%d\n", go(1, N));
}
