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

int N, x[10005];
vector<int> s[5];
bool valid = 1;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x[i]);
        s[(x[i] + 2) % 3 + 1].pb(x[i]);
    }
    // Not enough 1s and 2s to keep 3s from meeting
    if (s[3].size() >= 2 + s[1].size() + s[2].size()) {
        valid = 0;
    }
    // Not enough 3s to keep 1s and 2s from meeting
    if (!s[1].empty() && !s[2].empty() && s[3].empty()) {
        valid = 0;
    } 

    if (!valid) {
        printf("impossible");
        return 0;
    }

    deque<int> ret;
    if (!s[3].empty()) {
        ret.pb(s[3][0]); 
    }
    int j = 1;
    // Insert 2s
    for (int i = 0; i < s[2].size(); i++) {
        ret.pb(s[2][i]);
        if (j < s[3].size()) {
            ret.pb(s[3][j]);
            j += 1;
        }
    }
    // Insert 1s
    for (int i = 0; i < s[1].size(); i++) {
        ret.push_front(s[1][i]);
        if (j < s[3].size()) {
            ret.push_front(s[3][j]);
            j += 1;
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
}
