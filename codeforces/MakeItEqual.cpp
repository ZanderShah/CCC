#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int n, k, stop = 1e9;
long long towers[MAXN], tower = 0, cuts = 0;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1, h; i <= n; ++i) {
        scanf("%d", &h);
        ++towers[1];
        --towers[h + 1];
        stop = min(h, stop);
    }
    for (int i = 1; i < MAXN; ++i) {
        towers[i] += towers[i - 1];
    }

    for (int i = MAXN - 1; i > stop; --i) {
        if (tower + towers[i] > k) {
            ++cuts;
            tower = 0;
        }
        tower += towers[i];
    }
    printf("%lld\n", cuts + (tower + k - 1) / k);
}
