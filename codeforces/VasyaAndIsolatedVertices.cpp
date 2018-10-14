#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main() {
    scanf("%lld %lld", &n, &m);
    if (m == 0) {
        printf("%lld %lld\n", n, n);
        return 0;
    }
    printf("%lld ", max(0ll, n - m * 2));
    for (long long i = 1; i <= n; ++i) {
        if (i * (i - 1) / 2 >= m) {
            printf("%lld\n", n - i);
            return 0;
        }
    }
    printf("0\n");
}
