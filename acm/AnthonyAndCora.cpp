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

int N, M;
double P[2005];
double dp[2005][2005];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N + M - 1; ++i)
        scanf("%lf", &P[i]);

    memset(dp, 0, sizeof dp);
    // P(1 W | i G) = 1
    for (int i = 0; i <= N + M - 1; ++i)
        dp[i][0] = 1;
    // P(j W | i G)
    for (int i = 1; i <= N + M - 1; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            // Lose game
            dp[i][j] += dp[i - 1][j] * (1 - P[i]);
            // Win game
            dp[i][j] += dp[i - 1][j - 1] * P[i];
        }
    }
    printf("%lf\n", dp[N + M - 1][M]);
}
