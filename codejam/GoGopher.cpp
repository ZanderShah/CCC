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

int T, A, a, R, C, r, c;
bool G[15][25];

int quality(int i, int j)
{
    int ret = 0;
    for (int ii = i - 1; ii <= i + 1; ++ii)
    {
        for (int jj = j - 1; jj <= j + 1; ++jj)
            ret += !G[ii][jj];
    }
    return ret;
}

int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &A);
        if (A == 20)
        {
            R = 5;
            C = 4;
        }
        else
        {
            R = 10;
            C = 20;
        }

        memset(G, 0, sizeof G);
        a = 0;

        while (a != A)
        {
            int best_guess = 0;
            for (int i = 2; i <= R - 1; ++i)
            {
                for (int j = 2; j <= C - 1; ++j)
                {
                    int cur_guess = quality(i, j);
                    if (best_guess < cur_guess)
                    {
                        best_guess = cur_guess;
                        r = i;
                        c = j;
                    }
                }
            }
            printf("%d %d\n", r, c);
            fflush(stdout);

            scanf("%d %d", &r, &c);
            if (r <= 0 && c <= 0)
                break;

            G[r][c] = 1;
        }
    }
}
