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

int T, H, h, S, X, Y, Z;
double dp[25][625], sol;
char cc;
double opt;
string s;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.precision(8);

	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> H >> S;
		opt = 0;
		for (int d = 0; d < S; d++) {
			h = H;
			cc = '$';
			Z = sol = 0;
			memset(dp, 0, sizeof dp);

			cin >> s;
			sscanf(s.c_str(), "%dd%d%c%d", &X, &Y, &cc, &Z);

			if (cc == '-') {
				h += Z;
			} else if (cc == '+') {
				h -= Z;
			}

			if (h <= 0) {
				opt = 1;
			}

			for (int i = 1; i <= Y; i++) {
				dp[1][i] = 1.0 / Y;
			}

			// Number of rolls
			for (int i = 2; i <= X; i++) {
				// What you rolled
				for (int j = 1; j <= Y; j++) {
					// All possible previous values
					for (int k = 1; k <= X * Y - j; k++) {
						if (dp[i - 1][k] != 0) {
							dp[i][k + j] += dp[i - 1][k] / Y;
						}
					}
				}
			}

			for (int i = 1; i <= X * Y; i++) {
				if (i >= h) {
					sol += dp[X][i];
				}
			}

			opt = max(opt, sol);
		}

		cout << "Case #" << c << ": " << opt << endl;
	}
}
