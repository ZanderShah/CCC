#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const double EPS = 1e-15;
const int MAXN = 1e5 + 5;

int n, up = 0, down = 0;
pair<int, int> l[MAXN];

bool v(double r) {
    double lo_x = -1e15, hi_x = 1e15;
    for (int i = 0; i < n; ++i) {
        if (l[i].y >= 2 * r + EPS)
            return false;
        double d = sqrt(r * r - (l[i].y - r) * (l[i].y - r));
        lo_x = max(lo_x, l[i].x - d);
        hi_x = min(hi_x, l[i].x + d);
    }
    return lo_x - hi_x <= EPS;
}

int main() {
    scanf("%d", &n); for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l[i].x, &l[i].y);
        if (l[i].y > 0)
            ++up;
        else
            ++down;
    }
    if (up && down) {
        printf("-1\n");
        return 0;
    }
    if (down) {
        for (int i = 0; i < n; ++i) {
            l[i].y = -l[i].y;
        }
    }
    double lo = 0, hi = 1e15, mid = (lo + hi) / 2;
    while ((hi - lo) / max(1., hi) >= EPS) {
        if (v(mid)) {
            hi = mid - EPS;
        } else {
            lo = mid + EPS;
        }
        mid = (lo + hi) / 2;
    }
    printf("%lf\n", lo);
}
