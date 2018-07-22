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

const ll MOD = 1e9 + 7;

int T, N;
bool g[5][1005];
char c;
ll dp[5][1005];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);

        memset(g, 0, sizeof g);
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= N; ++j) {
                scanf(" %c", &c);
                g[i][j] = c == '.';
            }
        }

        dp[1][0] = 1;
        for (int i = 1; i <= N; ++i) {
            if (g[1][i] && g[2][i]) {
                dp[1][i] = dp[2][i - 1];
            }
            if (g[2][i]) {
                if (g[1][i]) {
                    dp[2][i] = dp[1][i - 1];
                }
                if (g[3][i]) {
                    dp[2][i] = (dp[2][i] + dp[3][i - 1]) % MOD;
                }
            }
            if (g[3][i] && g[2][i]) {
                dp[3][i] = dp[2][i - 1];
            }
        }
        printf("Case #%d: %lld\n", t, dp[3][N]);
    }
}
