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

string s, ss;
int n, x, dp[105][105];
double b = 1 << 30;

int edit(int i, int j) {
    if (i == s.length() || j == ss.length()) {
        return max(s.length() - i, ss.length() - j);
    } 
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ret = 1 << 30;
    if (s[i] == ss[j]) {
        ret = min(ret, edit(i + 1, j + 1));
    }
    ret = min(ret, edit(i + 1, j) + 1);
    ret = min(ret, edit(i, j + 1) + 1);
    ret = min(ret, edit(i + 1, j + 1) + 1);
    return dp[i][j] = ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        int v = 0;
        for (int j = 0; j < x; j++) {
            cin >> ss;
            for (int ii = 0; ii <= s.length(); ii++) {
                dp[ii][0] = ii;
            }
            for (int jj = 0; jj <= ss.length(); jj++) {
                dp[0][jj] = jj;
            }
            for (int ii = 1; ii <= s.length(); ii++) {
                for (int jj = 1; jj <= ss.length(); jj++) {
                    dp[ii][jj] = 105;
                    if (s[ii - 1] == ss[jj - 1]) {
                        dp[ii][jj] = dp[ii - 1][jj - 1];
                    }
                    dp[ii][jj] = min(dp[ii][jj], dp[ii - 1][jj] + 1);
                    dp[ii][jj] = min(dp[ii][jj], dp[ii][jj - 1] + 1);
                    dp[ii][jj] = min(dp[ii][jj], dp[ii - 1][jj - 1] + 1);
                }
            }
            v += dp[s.length()][ss.length()];
        }
        b = min(b, v * 1.0 / x);
    }
    printf("%lf\n", b);
}
