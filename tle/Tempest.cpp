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

int N, M, X, Y, Q, f, l;
pair<pii, int> m[2 * MAXN];
vector<pii> adj[MAXN];
ll d_x[MAXN], d_y[MAXN];
bool vis[MAXN];
priority_queue<pll> pq;

int main()
{
    scanf("%d %d %d %d", &N, &M, &X, &Y);
    for (int i = 1; i <= N; ++i)
        d_x[i] = d_y[i] = 1 << 30;
    for (int i = 1; i <= M; ++i)
    {
        scanf("%d %d %d", &m[i].x.x, &m[i].x.y, &m[i].y);
        adj[m[i].x.x].pb(mp(m[i].x.y, m[i].y));
        adj[m[i].x.y].pb(mp(m[i].x.x, m[i].y));
    }

    memset(vis, 0, sizeof vis);
    d_x[X] = 0;
    pq.push(mp(0, X));
    while (!pq.empty())
    {
        int x = pq.top().y;
        pq.pop();

        if (vis[x])
            continue;
        vis[x] = 1;

        for (pii y : adj[x])
        {
            if (vis[y.x] || d_x[x] + y.y >= d_x[y.x])
                continue;
            d_x[y.x] = d_x[x] + y.y;
            pq.push(mp(-d_x[y.x], y.x));
        }
    }

    memset(vis, 0, sizeof vis);
    d_y[Y] = 0;
    pq.push(mp(0, Y));
    while (!pq.empty())
    {
        int x = pq.top().y;
        pq.pop();

        if (vis[x])
            continue;
        vis[x] = 1;

        for (pii y : adj[x])
        {
            if (vis[y.x] || d_y[x] + y.y >= d_y[y.x])
                continue;
            d_y[y.x] = d_y[x] + y.y;
            pq.push(mp(-d_y[y.x], y.x));
        }
    }

    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i)
    {
        scanf("%d %d", &f, &l);

        if (f == 1)
        {
            printf("%lld\n", d_x[l] == d_y[l] ? d_x[l] : -1);
        }
        else
        {
            ll d_x1 = d_x[m[l].x.x], d_x2 = d_x[m[l].x.y];
            ll d_y1 = d_y[m[l].x.x], d_y2 = d_y[m[l].x.y];

            if (d_x1 == d_y1 && d_x2 == d_y2)
            {
                printf("%lld\n", min(d_x1, d_x2));
            }
            else if (d_x1 == d_y1)
            {
                printf("%lld\n", d_x1 == m[l].y + min(d_x2, d_y2) ? -1 : d_x1);
            }
            else if (d_x2 == d_y2)
            {
                printf("%lld\n", d_x2 == m[l].y + min(d_x1, d_y1) ? -1 : d_x2);
            }
            else if ((d_x1 < d_y1) ^ (d_x2 < d_y2))
            {
                ll d_1 = min(d_x1, d_y1), d_2 = min(d_x2, d_y2);
                printf("%f\n", max(d_1, d_2) + (m[l].y - abs(d_1 - d_2)) / 2.0);
            }
            else
            {
                printf("-1\n");
            }
        }
    }
}
