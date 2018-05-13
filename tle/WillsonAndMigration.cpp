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

const int MAXN = 1e4 + 5;
int N, x[MAXN], y[MAXN];
double dx[MAXN], dy[MAXN];
ll R;

int main()
{
    scanf("%d %lld", &N, &R);
    R = R * R;

    for (int i = 1, v; i <= N; ++i)
    {
        scanf("%d %d %lf %lf %d", &x[i], &y[i], &dx[i], &dy[i], &v);
        dx[i] -= x[i];
        dy[i] -= y[i];
        // Normalize
        double len = sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
        dx[i] = dx[i] / len * v;
        dy[i] = dy[i] / len * v;
    }

    for (int i = 2; i <= N; ++i)
    {
        ll delta_x = x[1] - x[i], delta_y = y[1] - y[i];

        if (delta_x * delta_x + delta_y * delta_y <= R)
        {
            printf("%d\n", i);
            continue;
        }

        double delta_vx = dx[1] - dx[i], delta_vy = dy[1] - dy[i];

        double t = -(delta_x * delta_vx + delta_y * delta_vy) / (delta_vx * delta_vx + delta_vy * delta_vy);
        if (t < 0)
            continue;

        double t_x = delta_x + delta_vx * t, t_y = delta_y + delta_vy * t;

        if (t_x * t_x + t_y * t_y <= R)
            printf("%d\n", i);
    }
}
