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

const int MAXN = 1e5 + 5;

int t, M, N, c[MAXN], r[3], dp[3];

int main() {
	while (1) {
		scan(N); scan(M);

		if (N == 0 && M == 0) {
			return 0;
		}

		memset(r, 0, sizeof r);

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				scan(c[j]);
			}

			memset(dp, 0, sizeof dp);
			dp[1] = c[1];
			for (int j = 2; j <= M; j++) {
				dp[j % 3] = max(dp[(j + 2) % 3], dp[(j + 1) % 3] + c[j]);
			}

			if (i == 1) {
				r[i] = dp[M % 3];
			} else {
				r[i % 3] = max(r[(i + 2) % 3], r[(i + 1) % 3] + dp[M % 3]);
			}
		}

		printf("%d\n", r[N % 3]);
	}
}
