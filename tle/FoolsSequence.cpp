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

int T, L;
ll dp[505], N;

string go(ll n, int l) {
	if (l <= 1) {
		return "";
	}
	if (l == 2) {
		return "69";
	}
	if (l == 3) {
		return "420";
	}

	// 420 starts
	ll p = dp[l - 3];
	if (n <= p) {
		return "420" + go(n, l - 3);
	}
	return "69" + go(n - p, l - 2);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;

	dp[0] = dp[1] = 0;
	dp[2] = dp[3] = 1;

	for (int i = 4; i <= 500; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int t = 0; t < T; t++) {
		cin >> N;

		for (L = 2; dp[L] < N; L++) {
			N -= dp[L];
		}

		// cout << N << " " << L << endl;

		cout << go(N, L) << endl;
	}
}
