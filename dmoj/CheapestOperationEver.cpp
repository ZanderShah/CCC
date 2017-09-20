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

const int MAXN = 1e5 + 5;

int N, H;
ll c[MAXN], dp[MAXN];

inline ll A(int i, int j) {
	return 1ll * (c[i] - c[j]) * (c[i] - c[j]);
}

int go(int i) {
	if (N < i) {
		return 0;
	}
	if (dp[i] != -1) {
		return dp[i];
	}
	ll ret = 1e15;
	for (int j = i; j <= N; j++) {
        if (A(i, j) > 2 * H) break;
		ret = min(ret, go(j + 1) + A(i, j) + H);
	}
    return dp[i] = ret;
}

int main() {
	scanf("%d %d", &N, &H);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &c[i]);
	}
	memset(dp, -1, sizeof dp);
	printf("%lld\n", go(1));
}
