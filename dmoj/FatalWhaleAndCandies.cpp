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

const int MAXN = 5000;
const ll INF = 1e12;

int N, P, s[MAXN];
unsigned short m[MAXN];
ll dp[2][MAXN];
vector<int> candies;

int main() {
	scan(N); scan(P);

	for (int i = 1; i <= N; ++i) {
		scan(s[i]);
		m[i] = s[i] % P;
	}

	dp[0][0] = 0;
	for (int j = 1; j < P; ++j) {
		dp[0][j] = -INF;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < P; ++j) {
			dp[1][j] = max(dp[0][j], dp[0][(j - m[i] + P) % P] + s[i]);
		}
		if (i == N) continue;
		for (int j = 0; j < P; ++j) {
			dp[0][j] = dp[1][j];
		}
	}

	printf("%lld\n", dp[1][0]);

	for (int i = N, t = 0; i >= 1; --i) {
		// Used this piece
		for (int j = 0; j < P; ++j) {
			if (dp[1][t] != dp[0][t] && dp[1][t] == dp[0][(j - m[i] + P) % P] + s[i]) {
				t = (j - m[i] + P) % P;
				candies.pb(i);
				break;
			}
		}

		// Reset level
		for (int j = 0; j < P; ++j) {
			dp[1][j] = dp[0][j];
		}

		// Rebuild last level
		for (int j = 0; j < P; ++j) {
			dp[0][(j - m[i - 1] + P) % P] = dp[1][j] - s[i - 1];
		}
	}

	printf("%lu\n", candies.size());
	for (int i = 0; i < candies.size(); i++) {
		printf("%d ", candies[i]);
	}
}
