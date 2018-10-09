#include <bits/stdc++.h>
using namespace std;

int n, L, a, c = 0, t, l, b = 0;

int main() {
    scanf("%d %d %d", &n, &L, &a);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &t, &l);
        b += (t - c) / a;
        c = t + l;
    }
    b += (L - c) / a;
    printf("%d\n", b);
}
