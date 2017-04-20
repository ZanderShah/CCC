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

struct Snowflake {
	int T, V, c;
};
vector<Snowflake> snow[51];

int R, C, S, B, K, M, dp[51][51][51][51], T, V, c, r;

// Position, Time, Snow, Heat
int fall(int p, int t, int s, int h) {
	if (R <= t) {
		return 0;
	}

	if (dp[p][t][s][h] != -1) {
		return dp[p][t][s][h];
	}

	int ret = 0;

	// See if you can catch a snowflake
	for (int i = 0; i < snow[t].size(); i++) {
		if (abs(p - snow[t][i].c) <= M && s + 1 <= K && h + snow[t][i].T < B) {
			ret = max(ret, fall(snow[t][i].c, t + 1, s + 1, h + snow[t][i].T) + snow[t][i].V);
		}
	}

	// Move
	for (int i = max(1, p - M); i <= min(C, p + M); i++) {
		ret = max(ret, fall(i, t + 1, s, h));
	}

	return dp[p][t][s][h] = ret;
}

int main() {
	scanf("%d %d %d %d %d %d", &R, &C, &S, &B, &K, &M);
	for (int i = 0; i < S; i++) {
		scanf("%d %d %d %d", &T, &V, &c, &r);
		snow[r - 1].pb(Snowflake {T, V, c});
	}
	memset(dp, -1, sizeof dp);
	printf("%d", fall(1, 0, 0, 0));
}
