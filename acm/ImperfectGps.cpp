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

int n, T, x[105], y[105], t[105];
double total = 0, tracked = 0;

inline double dist(double x, double y, double xx, double yy) {
    return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

int main() {
    scanf("%d %d", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x[i], &y[i], &t[i]);
    }
    for (int i = 1; i < n; i++) {
        total += dist(x[i - 1], y[i - 1], x[i], y[i]);
    }

    double xx = x[0], yy = y[0];

    for (int tt = 0, i = 1; i < n; i++) {
        double dx = (x[i] - x[i - 1]) * 1.0 / (t[i] - t[i - 1]), dy = (y[i] - y[i - 1]) * 1.0 / (t[i] - t[i - 1]);
        while (tt + T <= t[i]) {
            tt += T;
            tracked += dist(xx, yy, x[i - 1] + dx * (tt - t[i - 1]), y[i - 1] + dy * (tt - t[i - 1]));
            xx = x[i - 1] + dx * (tt - t[i - 1]);
            yy = y[i - 1] + dy * (tt - t[i - 1]);
        }
    }
    tracked += dist(xx, yy, x[n - 1], y[n - 1]);
    printf("%.9lf\n", (total - tracked) * 100 / total);
}
