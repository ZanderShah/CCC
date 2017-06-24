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

int N, X;
vector<int> s[2025], S[2025];
bool vis[2015];

int main() {
    cin >> N >> X;
    if (X >= N) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N * X; i++) {
        s[i / X].pb(i + 1);
    }
    
    for (int j = 0; j < X; j++) {
        for (int i = 0; i < N; i++) {
            S[i].pb(s[(i + 1 + j) % N][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= X; j++) {
            cout << (X * i + j) << " ";
        }
        for (int j = 0; j < X; j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
}
