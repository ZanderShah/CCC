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

int N, x, c[3];

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        if (x % 4 == 0) {
            c[2] += 1;
        } else if (x % 2 == 0) {
            c[1] += 1;
        } else {
            c[0] += 1;
        }
    }
    // 4 can be next to anything
    // 2 have to be next to 2 or 4
    // 0 have to be next to a 4
    
    // 0 next to 2
    if (c[0] != 0 && c[1] != 0 && c[2] == 0) {
        cout << "No" << endl;
        return 0;
    }
    // 0 not next to 4
    if ((c[0] != 0 && c[2] == 0) || (c[0] - c[2] >= 2)) {
        cout << "No" << endl;
        return 0;
    }
    if (c[0] - c[2] == 1 && c[1] != 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
