#include <bits/stdc++.h>
using namespace std;

int n, m;
char c, g[1005][1005];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &c);
            g[i][j] = c == '#';
        }
    }
    for (int i = 0; i < n - 2; ++i) {
        for (int j = 0; j < m - 2; ++j) {
            bool all = g[i][j];
            all &= g[i][j + 1];
            all &= g[i][j + 2];
            all &= g[i + 1][j];
            all &= g[i + 1][j + 2];
            all &= g[i + 2][j];
            all &= g[i + 2][j + 1];
            all &= g[i + 2][j + 2];
            if (all) {
                g[i][j] = g[i][j + 1] = g[i][j + 2] = 3;
                g[i + 1][j] = g[i + 1][j + 2] = 3;
                g[i + 2][j] = g[i + 2][j + 1] = g[i + 2][j + 2] = 3;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}
