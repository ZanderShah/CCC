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

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

const int MAXN = 1e6 + 5;
int n, p, r;
pii l[MAXN];

int main() {
    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &l[i].x, &l[i].y);
    int r = (n * p - 1) / 100;

    bool v = false;
    for (int t = 0; t < 75 && !v; ++t)
    {
        int c = 0;
        int a = rand() % n;
        unordered_map<ll, int> g;

        for (int i = 0; i < n; ++i)
        {
            if (i == a)
                continue;

            int x = l[i].x - l[a].x;
            int y = l[i].y - l[a].y;
            int gg = gcd(x, y);
            x /= gg;
            y /= gg;

            v |= ++g[((x * 1ll) << 31) + y] >= r;
        }
    }

    if (r <= 1)
        v = true;

    printf("%s\n", v ? "possible" : "impossible");
}
