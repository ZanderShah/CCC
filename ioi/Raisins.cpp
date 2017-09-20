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

int N, M, g[51][51], dp[51][51][51][51];

int go(int i, int j, int l, int r) {
    if (i == j && l == r) {
        return 0;
    }
    if (dp[i][j][l][r] != -1) {
        return dp[i][j][l][r];
    }
    int ret = 1 << 29;
    for (int ii = i; ii + 1 <= j; ii++) {
        ret = min(ret, go(i, ii, l, r) + go(ii + 1, j, l, r));
    }
    for (int ll = l; ll + 1 <= r; ll++) {
        ret = min(ret, go(i, j, l, ll) + go(i, j, ll + 1, r));
    }
    return dp[i][j][l][r] = ret + g[j][r] - g[i - 1][r] - g[j][l - 1] + g[i - 1][l - 1];
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &g[i][j]);
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", go(1, N, 1, M));
}
