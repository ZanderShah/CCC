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

int N, L, W;
int p[2005];
double X, dp[2005][2005];

double place(int i, int l, int r)
{
    if (l > N / 2 || r > N / 2)
        return 1 << 30;
    if (l == N / 2 && r == N / 2)
        return 0;

    if (dp[l][r] >= 0)
    {
        return dp[l][r];
    }

    dp[l][r] = 1 << 30;
    if (l < N / 2)
    {
        double xl = fabs(X * l - p[i]);
        dp[l][r] = min(dp[l][r], place(i + 1, l + 1, r) + xl);
    }
    if (r < N / 2)
    {
        double xr = fabs(X * r - p[i]);
        dp[l][r] = min(dp[l][r], place(i + 1, l, r + 1) + sqrt(W * W + xr * xr));
    }
    return dp[l][r];
}

int main() {
    scanf("%d", &N);
    scanf("%d %d", &L, &W);
    X = L * 1.0 / (N / 2 - 1);

    for (int i = 0; i < N; ++i)
        scanf("%d", &p[i]);
    sort(p, p + N);

    for (int i = 0; i <= N / 2; ++i)
    {
        for (int j = 0; j <= N / 2; ++j)
            dp[i][j] = -1;
    }

    printf("%.9lf\n", place(0, 0, 0));
}
