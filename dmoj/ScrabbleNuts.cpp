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
#include <cstdio>
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
typedef unordered_map<int, int> umii;

int N, M, dp[2][10005], e;
string a, b;

int main () {
	cin >> N >> M >> a >> b;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i == 0) {
				dp[1][j] = j;
			} else if (j == 0) {
				dp[1][j] = i;
			} else if (a[i - 1] == b[j - 1]) {
				dp[1][j] = dp[0][j - 1];
			} else {
				dp[1][j] = min(dp[0][j], min(dp[1][j - 1], dp[0][j - 1])) + 1;
			}
		}
		swap(dp[0], dp[1]);
	}

	for (int i = 1; i < M; i++) {
		e += dp[0][i];
	}

	cout << e;
}
