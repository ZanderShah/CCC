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

const ll BIG = 1ll << 35;

int N, K, i2, i1, i0, s3, s2, s1, s0;
ll a[3][10005], v2, v1, v0, dp[4][10005];

int magic(int i) {
	if (N <= 1000) {
		return K;
	}
	return i <= N - 5 ? K / 3 : K;
}

int main() {
	scan(N);
	scan(K);

	for (int i = 1; i <= N; ++i) {
		scan(a[2][i]);
		a[2][i] *= 10;
	}
	for (int i = 2; i <= N; i++) {
		a[1][i] = a[2][i] + a[2][i - 1] - min(a[2][i], a[2][i - 1]) / 2;
	}
	for (int i = 3; i <= N; i++) {
		a[0][i] = a[2][i] + a[2][i - 1] + a[2][i - 2] - min(a[2][i], min(a[2][i - 1], a[2][i - 2]));
	}

	s0 = s1 = 0;
	s2 = 1;

	for (int i = 1; i <= N; ++i) {
		i2 = i1 = i0 = s3 = 0;

		while(s3 < magic(i) && (i2 < s2 || i1 < s1 || i0 < s0)) {
			v2 = v1 = v0 = BIG;

			if (i2 < s2) {
				v2 = dp[2][i2] + a[2][i];
			}
			if (i1 < s1) {
				v1 = dp[1][i1] + a[1][i];
			}
			if (i0 < s0) {
				v0 = dp[0][i0] + a[0][i];
			}

			if (v0 < v1 && v0 < v2) {
				if (s3 == 0 || dp[3][s3 - 1] != v0) {
					dp[3][s3++] = v0;
				}
				++i0;
			} else if (v1 < v2) {
				if (s3 == 0 || dp[3][s3 - 1] != v1) {
					dp[3][s3++] = v1;
				}
				++i1;
			} else {
				if (s3 == 0 || dp[3][s3 - 1] != v2) {
					dp[3][s3++] = v2;
				}
				++i2;
			}
		}

		swap(dp[0], dp[1]);
		s0 = s1;
		swap(dp[1], dp[2]);
		s1 = s2;
		swap(dp[2], dp[3]);
		s2 = s3;
	}

	if (s2 < K) {
		printf("-1\n");
	} else {
		printf("%.1f\n", dp[2][K - 1] / 10.0);
	}
}
