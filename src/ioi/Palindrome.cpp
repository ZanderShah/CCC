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
#include <cassert>

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

const int MAXN = 5005;
int N, dp[2][MAXN];
string a;

int main() {
	cin >> N;
	cin >> a;
	a = '$' + a;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (a[i] == a[N - j + 1]) {
				dp[1][j] = dp[0][j - 1] + 1;
			}
			dp[1][j] = max(dp[1][j], dp[0][j]);
			dp[1][j] = max(dp[1][j], dp[1][j - 1]);
		}
		for (int j = 1; j <= N; j++) {
			dp[0][j] = dp[1][j];
		}
	}

	printf("%d\n", N - dp[0][N]);
}
