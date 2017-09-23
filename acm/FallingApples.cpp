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

int R, C;
char g[50005][10], o[50005][10];

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &g[i][j]);
            o[i][j] = '.';
            if (g[i][j] == '#') {
                o[i][j] = '#';
            }
        }
    }
    for (int j = 0; j < C; j++) {
        g[R][j] = '#';

        int a = 0;
        for (int i = 0; i <= R; i++) {
            if (g[i][j] == 'a') {
                a += 1;
            } else if (g[i][j] == '#') {
                for (int k = i - 1; k >= i - a; k--) {
                    o[k][j] = 'a';
                }
                a = 0;
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", o[i][j]);
        }
        printf("\n");
    }
}
