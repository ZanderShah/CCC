#include <bits/stdc++.h>

using namespace std;

int t, s, a, b, c, buy;
long long take;

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        scanf("%d %d %d %d", &s, &a, &b, &c);
        buy = s / c;
        take = buy * 1ll / a * b;
        printf("%lld\n", buy + take);
    }
}
