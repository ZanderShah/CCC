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

int N, n, K, M;
ll C[105], V[105][505], dp[105][505];

ll minimize(int m, int k) {
	k++;
	// Splitting C[m] into k + 1 parts
	ll p = C[m] / k;
	// Number of longer parts
	ll l = C[m] - p * k;
	// Total noise of shorter and longer parts
	return (k * p + l * 2) * (p + 1) / 2;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &n);
		C[n]++;
	}
	// Min sum for k clears at building m
	for (int m = 1; m <= M; m++) {
		V[m][0] = C[m] * (C[m] + 1) / 2;
		dp[m][0] = 1 << 30;
		for (int k = 1; k <= K; k++) {
			V[m][k] = minimize(m, k);
			dp[m][k] = 1 << 30;
		}
	}

	// Current building
	for (int m = 1; m <= M; m++) {
		// Current clears
		for (int k = 0; k <= K; k++) {
			// Used kk clears on this building
			for (int kk = 0; kk <= k; kk++) {
				dp[m][k] = min(dp[m][k], dp[m - 1][k - kk] + V[m][kk]);
			}
		}
	}

	printf("%lld\n", dp[M][K]);
}
