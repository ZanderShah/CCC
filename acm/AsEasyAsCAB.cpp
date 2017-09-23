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

char L;
int N, used;
string s[1005];
vector<int> ord;
bool adj[26][26];

bool in[26], start[26], vis[26];

void top(int i) {
    if (vis[i]) {
        return;
    }
    vis[i] = 1;
    for (int j = 0; j < 26; j++) {
        if (adj[i][j]) {
            top(j);
        }
    }
    ord.pb(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> N;

    for (int i = 0; i <= L - 'a'; i++) {
        start[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i].length(); j++) {
            in[s[i][j] - 'a'] = 1;
        }
        if (i == 0) continue;
        for (int j = 0; j < min(s[i - 1].length(), s[i].length()); j++) {
            if (s[i - 1][j] != s[i][j]) {
                // Character at s[i - 1][j] must be less than s[i][j]
                adj[s[i][j] - 'a'][s[i - 1][j] - 'a'] = 1;
                start[s[i - 1][j] - 'a'] = 0;
                break;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (in[i]) {
            used++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (in[i] && start[i]) {
            top(i);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (adj[i][j] && adj[j][i]) {
                printf("IMPOSSIBLE\n");
                return 0; 
            }
        }
    }

    if (ord.size() < used) {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    if (used <= L - 'a') {
        printf("AMBIGUOUS\n");
        return 0; 
    }
    for (int i = 1; i < ord.size(); i++) {
        if (!adj[ord[i]][ord[i - 1]]) {
            printf("AMBIGUOUS\n");
            return 0;
        }
    }

    for (int i = 0; i < ord.size(); i++) {
        printf("%c", (char)(ord[i] + 'a'));
    }
    printf("\n");
}