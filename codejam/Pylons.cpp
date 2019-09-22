#include <bits/stdc++.h>
using namespace std;

int T, R, C, r, c;
int vis[5][5];

bool bf(int r, int c) {
    bool done = true;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            done &= vis[i][j] != 0;
        }
    }

    if (done) return true;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (i == r) continue;
            if (j == c) continue;
            if (r - c == i - j) continue;
            if (r + c == i + j) continue;
            if (vis[i][j]) continue;

            vis[i][j] = vis[r][c] + 1;
            if (bf(i, j)) return true;
            vis[i][j] = 0;
        }
    }

    return false;
}

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &R, &C);
        printf("Case #%d: ", t);

        if (R < 5 && C < 5) {
            // Brute force.
            bool stay = true;

            for (int i = 0; i < R && stay; ++i) {
                for (int j = 0; j < C && stay; ++j) {
                    memset(vis, 0, sizeof vis);
                    vis[i][j] = 1;
                    stay &= !bf(i, j);
                }
            }

            if (stay) {
                printf("IMPOSSIBLE\n");
            } else {
                printf("POSSIBLE\n");
                for (int i = 1; i <= R * C; ++i) {
                    for (int r = 0; r < R; ++r) {
                        for (int c = 0; c < C; ++c) {
                            if (vis[r][c] == i) printf("%d %d\n", r + 1, c + 1);
                        }
                    }
                }
            }
            continue;
        }

        printf("POSSIBLE\n");

        bool swapped = false;
        if (R > C) {
            swap(R, C);
            swapped = true;
        }

        if (R % 2 != 0) {
            // Three.
            for (int i = 1; i <= C; ++i) {
                if (!swapped) {
                    printf("1 %d\n", i);
                    printf("2 %d\n", (i + 2) % C + 1);
                    printf("3 %d\n", i);
                } else {
                    printf("%d 1\n", i);
                    printf("%d 2\n", (i + 2) % C + 1);
                    printf("%d 3\n", i);
                }
            }
        }

        for (int i = (R % 2 == 0 ? 0 : 3); i + 2 <= R; i += 2) {
            for (int j = 1; j <= C; ++j) {
                if (!swapped) {
                    printf("%d %d\n", i + 1, j);
                    printf("%d %d\n", i + 2, (j + 2) % C + 1);
                } else {
                    printf("%d %d\n", j, i + 1);
                    printf("%d %d\n", (j + 2) % C + 1, i + 2);
                }
            }
        }
    }
}
