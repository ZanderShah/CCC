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

int T, N, M, v[305][305];
ll dp[305][305];

ll pie(int i, int j) {
	if (j >= N) {
		return 0;
	}
	if (i >= N || i > j) {
		return 1e10;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	ll ret = pie(i + 1, j);
	for (int k = 1; k <= M; k++) {
		ret = min(ret, pie(i + 1, j + k) + v[i][k] + k * k);
	}

	return dp[i][j] = ret;
}

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; r++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= M; j++) {
				scanf("%d", &v[i][j]);
			}
			sort(v[i] + 1, v[i] + M + 1);
			for (int j = 1; j <= M; j++) {
				v[i][j] += v[i][j - 1];
			}
		}

		memset(dp, -1, sizeof dp);

		printf("Case #%d: %lld\n", r, pie(0, 0));
	}
}
