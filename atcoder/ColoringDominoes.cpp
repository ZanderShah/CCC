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

const int MOD = 1e9 + 7;

// last == 1 => |, last == 2 => =
int N, last = 0;
string s[2];
ll ans = 1;

int main() {
    cin >> N;
    cin >> s[0] >> s[1];
    for (int i = 0; i < N; i++) {
        if (s[0][i] == s[1][i]) {
            // |
            if (last == 0) {
                ans = ans * 3 % MOD;
            } else if (last == 1) {
                ans = ans * 2 % MOD;
            } 
            last = 1;
        } else {
            // =
            if (last == 0) {
                ans = ans * 6 % MOD;
            } else if (last == 1) {
                ans = ans * 2 % MOD; 
            } else {
                ans = ans * 3 % MOD;
            }
            last = 2;
            i++;
        }
    }    
    printf("%lld\n", ans);
}
