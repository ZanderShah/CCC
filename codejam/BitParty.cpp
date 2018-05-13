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

int T, R, B, C;
int M[1005], S[1005], P[1005];

bool valid(ll t)
{
    vector<ll> items;
    // For every cashier, find the max items they can be given in that time
    for (int i = 0; i < C; ++i)
    {
        ll t_left = t - P[i];
        ll n = max(0ll, min(t_left / S[i], 1ll * M[i]));
        items.pb(n);
    }
    sort(items.begin(), items.end());

    ll ret = 0;
    int r = 0;
    for (int c = C - 1; c >= 0 && r < R; --c, ++r)
        ret += items[c];

    return ret >= B;
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d %d %d", &R, &B, &C);
        for (int i = 0; i < C; ++i)
            scanf("%d %d %d\n", &M[i], &S[i], &P[i]);

        ll lo = 0, hi = 1ll << 60;
        while (lo <= hi)
        {
            ll med = (lo + hi) >> 1;
            if (valid(med))
                hi = med - 1;
            else
                lo = med + 1;
        }

        printf("Case #%d: %lld\n", t, lo);
    }
}
