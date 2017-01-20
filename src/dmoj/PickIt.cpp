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

int n, k[205], dp[205][205];

int pick(int l, int r) {
	if (l >= r) {
		return 0;
	}
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int ret = 0;
	for (int i = l + 1; i <= r - 1; i++) {
		ret = max(ret, pick(l, i) + pick(i, r) + k[l] + k[i] + k[r]);
	}
	return dp[l][r] = ret;
}

int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &k[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%d\n", pick(0, n - 1));
	}
}
