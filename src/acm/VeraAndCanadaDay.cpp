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

int N, x[MAXN], y[MAXN], v[MAXN], value[MAXN];

map<int, map<int, pii> > X, Y;
ll awe = 0;

void update(int i) {
    awe -= value[i];

    map<int, pii>::iterator xx = X[x[i]].find(y[i]);
    map<int, pii>::iterator yy = Y[y[i]].find(x[i]);
    int l = 0, r = 0, u = 0, d = 0;

    if (xx != X[x[i]].begin()) {
        --xx;
        l = xx->y.x;
        ++xx;
    }
    if (++xx != X[x[i]].end()) {
        r = xx->y.x;
    }
    if (yy != Y[y[i]].begin()) {
        --yy;
        u = yy->y.x;
        ++yy;
    }
    if (++yy != Y[y[i]].end()) {
        d = yy->y.x;
    }
    value[i] = max(u, d) + max(l, r);

    awe += value[i];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &x[i], &y[i], &v[i]);
        X[x[i]][y[i]] = mp(v[i], i);
        Y[y[i]][x[i]] = mp(v[i], i);

        map<int, pii>::iterator xx = X[x[i]].find(y[i]);
        map<int, pii>::iterator yy = Y[y[i]].find(x[i]);
        int l = 0, r = 0, u = 0, d = 0;

        if (xx != X[x[i]].begin()) {
            --xx;
            l = xx->y.x;
            update(xx->y.y);
            ++xx;
        }
        if (++xx != X[x[i]].end()) {
            r = xx->y.x;
            update(xx->y.y);
        }
        if (yy != Y[y[i]].begin()) {
            --yy;
            u = yy->y.x;
            update(yy->y.y);
            ++yy;
        }
        if (++yy != Y[y[i]].end()) {
            d = yy->y.x;
            update(yy->y.y);
        }
        value[i] = max(u, d) + max(l, r);
        awe += value[i];
        printf("%lld\n", awe);
    }
}