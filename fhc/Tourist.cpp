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

long long T, K, k, N, V;
bool v[55];
string s[55];

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> K >> V;
        for (int i = 0; i < N; ++i) {
            cin >> s[i];
            v[i] = 0;
        }
        k = K * (V - 1) % N;
        for (int i = 0; i < K; ++i, k = (k + 1) % N) {
            v[k] = 1;
        }
        cout << "Case #" << t << ":";
        for (int i = 0; i < N; ++i) {
            if (v[i]) cout << " " << s[i];
        }
        cout << endl;
    }
}
