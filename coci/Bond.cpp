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

int N, p[21];
double pp[21], dp[2][1 << 20];

int main() {
	scan(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scan(p[j]);
			pp[j] = p[j] / 100.0;
		}
		if (i == 0) {
			for (int j = 0; j < N; j++)
				dp[1][1 << j] = pp[j];
		} else {
			for (int j = 0; j < N; j++)
				for (int k = 0; k < (1 << N); k++)
					if (dp[0][k] && (k & (1 << j)) == 0)
						dp[1][k | (1 << j)] = max(dp[1][k | (1 << j)],
								dp[0][k] * pp[j]);
		}
		for (int j = 0; j < (1 << N); j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = 0;
		}
	}
	printf("%f\n", dp[0][(1 << N) - 1] * 100);
}
