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

const string C[3] = {"Forward", "Left", "Right"};
int x, y, n;
string s[55];

bool valid(int i, int dx, int dy, int xx, int yy) {
    if (n < i) {
        return xx == x && yy == y;
    }
    if (s[i] == C[0]) {
        return valid(i + 1, dx, dy, xx + dx, yy + dy);
    } else if (s[i] == C[1]) {
        // Up or Down
        if (dy == 1) {
            return valid(i + 1, -1, 0, xx, yy);
        } else if (dy == -1) {
            return valid(i + 1, 1, 0, xx, yy);
        } else if (dx == 1) {
            return valid(i + 1, 0, 1, xx, yy);
        } else {
            return valid(i + 1, 0, -1, xx, yy);
        }
    } else if (s[i] == C[2]) {
        // Up or Down
        if (dy == 1) {
            return valid(i + 1, 1, 0, xx, yy);
        } else if (dy == -1) {
            return valid(i + 1, -1, 0, xx, yy);
        } else if (dx == 1) {
            return valid(i + 1, 0, -1, xx, yy);
        } else {
            return valid(i + 1, 0, 1, xx, yy);
        }
    }
}

int main() {
    cin >> x >> y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) if (s[i] != C[j]) {
            string k = s[i];
            s[i] = C[j];
            if (valid(1, 0, 1, 0, 0)) {
                cout << i << " " << C[j] << endl;
                return 0;
            }
            s[i] = k;
        }
    }
}
