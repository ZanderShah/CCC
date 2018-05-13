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

int T, R, C, H, V;
string s;
int g[105][105], pref[105][105];

int sum(int r0, int c0, int r1, int c1)
{
    return pref[r1 + 1][c1 + 1] - pref[r1 + 1][c0] - pref[r0][c1 + 1] + pref[r0][c0];
}

bool solve(int ch)
{
    vector<int> rows;
    rows.pb(-1);
    // Run through rows until sum is equal to ch
    for (int r = 0; r < R; ++r)
    {
        int rr = rows.back();
        if (sum(rr + 1, 0, r, C - 1) == ch * (V + 1) && (r + 1 == R || sum(rr + 1, 0, r + 1, C - 1) != ch * (V + 1)))
            rows.pb(r);
    }

    if (rows.size() != H + 2 || rows.back() != R - 1)
        return false;

    vector<int> cols;
    cols.pb(-1);

    for (int c = 0; c < C; ++c)
    {
        int cc = cols.back();

        bool all_rows = true;
        for (int r = 0; r < rows.size() - 1; ++r)
            all_rows &= sum(rows[r] + 1, cc + 1, rows[r + 1], c) == ch;

        bool all_next_rows = c + 1 != C;
        if (all_next_rows)
        {
            for (int r = 0; r < rows.size() - 1; ++r)
                all_next_rows &= sum(rows[r] + 1, cc + 1, rows[r + 1], c + 1) == ch;
        }

        if (all_rows && !all_next_rows)
            cols.pb(c);
    }

    return cols.size() == V + 2 && cols.back() == C - 1;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> R >> C >> H >> V;

        bool all_zero = true;
        for (int i = 0; i < R; ++i)
        {
            cin >> s;
            for (int j = 0; j < C; ++j)
            {
                if (s[j] == '@')
                    g[i][j] = 1;
                else
                    g[i][j] = 0;

                all_zero &= g[i][j] == 0;
            }
        }

        if (all_zero)
        {
            printf("Case #%d: POSSIBLE\n", t);
            continue;
        }

        memset(pref, 0, sizeof pref);
        for (int i = 1; i <= R; ++i)
        {
            for (int j = 1; j <= C; ++j)
            {
                pref[i][j] = g[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        bool possible = false;
        // Run through every possible amount of chocolates in the column.
        // Must be a multiple of (V + 1)
        for (int ch = 1; ch * (V + 1) * (H + 1) <= R * C && !possible; ch++)
            possible |= solve(ch);

        printf("Case #%d: %s\n", t, possible ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
