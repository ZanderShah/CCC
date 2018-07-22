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

int T, C, B[105], A[105][505];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &C);
        for (int c = 0; c < C; ++c) {
            scanf("%d", &B[c]);
        }
        memset(A, 0, sizeof A);

        if (B[0] == 0 || B[C - 1] == 0) {
            printf("Case #%d: IMPOSSIBLE\n" ,t);
            continue;
        }

        int bucket = 0;
        int bucket_count = 0;
        int max_row = 0;

        for (int c = 0; c < C; ++c, bucket_count++) {
            while (bucket < C && bucket_count == B[bucket]) {
                bucket++;
                bucket_count = 0;
            }

            if (bucket == C) {
                break;
            }

            if (bucket < c) {
                // Slide Left.
                for (int cc = c, j = 0; bucket < cc; cc--, j++) {
                    A[j][cc] = -1;
                    max_row = max(max_row, j + 1);
                }
            } else if (bucket > c) {
                // Slide Right.
                for (int cc = c, j = 0; bucket > cc; cc++, j++) {
                    A[j][cc] = 1;
                    max_row = max(max_row, j + 1);
                }
            }
        }

        printf("Case #%d: %d\n" ,t, max_row + 1);
        for (int i = 0; i < max_row + 1; ++i) {
            for (int j = 0; j < C; ++j) {
                if (A[i][j] == 0) {
                    printf(".");
                } else if (A[i][j] == -1) {
                    printf("/");
                } else {
                    printf("\\");
                }
            }
            printf("\n");
        }
    }
}
