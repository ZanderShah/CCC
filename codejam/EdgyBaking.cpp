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

int T, N, P, w, h;

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d %d", &N, &P);
        double p_left = P;

        for (int i = 0; i < N; ++i)
        {
            scanf("%d %d", &w, &h);
            p_left -= 2 * w + 2 * h;
        }

        double ans = 0;

        for (int i = 1; i <= N; ++i)
        {
            double lows = i * 2 * min(w, h);
            double fulls = i * 2 * sqrt(w * w + h * h);

            if (fulls <= p_left)
                ans = fulls;
            else if (lows <= p_left && p_left <= fulls)
                ans = p_left;
        }

        printf("Case #%d: %lf\n", t, P - (p_left - ans));
    }
}
