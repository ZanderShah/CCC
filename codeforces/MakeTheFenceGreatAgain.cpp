#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;
int Q;
long long dp[MAXN][3];

int main() {
    scanf("%d", &Q);

    for (int q = 0, n; q < Q; ++q) {
        scanf("%d", &n);

        int a_i = -1;
        for (int i = 1, a, b; i <= n; ++i) {
            scanf("%d %d", &a, &b);

            dp[i][0] = dp[i][1] = dp[i][2] = 1ll << 60;

            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (a_i + j != a + k) {
                        dp[i][k] = min(dp[i][k], dp[i - 1][j] + b * k);
                    }
                }
            }

            a_i = a;
        }

        printf("%lld\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
}
