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

const int MOD = 1e9 + 7;
int n, w, h, dp[2][10005];
ll p = 0;

int main()
{
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 0; i <= h; ++i)
    {
        if (i * w <= n)
            p++;
    }
    memset(dp, 0, sizeof dp);

    dp[0][n] = 1;
    for (int i = 1; i <= w; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            dp[1][j] = dp[0][min(n, j + h)];
            if (j != 0)
                dp[1][j] = (dp[1][j] - dp[0][j - 1] + MOD) % MOD;
        }
        dp[0][0] = dp[1][0];
        dp[1][0] = 0;
        for (int j = 1; j <= n; ++j)
        {
            dp[0][j] = (dp[0][j - 1] + dp[1][j]) % MOD;
            dp[1][j] = 0;
        }
    }

    printf("%lld\n", dp[0][n] - p);
}
