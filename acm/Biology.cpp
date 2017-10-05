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

int A, B, a[5], b[5], c[26], res[9];

bool flush() {
    for (int i = 1; i < 5; i++) {
        if (b[0] != b[i]) return 0;
    }
    return 1;
}

bool straight() {
    for (int i = 0; i < 5; i++) {
        c[i] = a[i];
    }
    sort(c, c + 5);
    for (int i = 1; i < 5; i++) {
        if (c[i] - c[i - 1] != 1) return 0;
    }
    return 1;
}

bool one(int t) {
    for (int i = 0; i < 5; i++) {
        c[a[i]] = 0;
    }
    for (int i = 0; i < 5; i++) {
        c[a[i]]++;
        if (c[a[i]] == t) {
            return 1;
        }
    }
    return 0;
}

bool two(int s, int t) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < 5; i++) {
        c[a[i]]++;
    }

    bool sc = 0, st = 0;

    sort(c, c + 24);

    for (int i = 24; i >= 0; i--) {
        if (c[i] >= s && !sc) {
            sc = 1;
        } else if (c[i] >= t) {
            st = 1;
        }
    }
    return sc && st;
}

int main() {
    scanf("%d %d", &A, &B);
    scanf("%d %d %d %d", &a[0], &b[0], &a[1], &b[1]);
    memset(res, 0, sizeof res);
    for (int i = 0; i < A * B; i++) {
        a[2] = i / B;
        b[2] = i % B;

        if (a[0] == a[2] && b[0] == b[2]) continue;
        if (a[1] == a[2] && b[1] == b[2]) continue;

        for (int j = i + 1; j < A * B; j++) {
            a[3] = j / B;
            b[3] = j % B;
            if (a[0] == a[3] && b[0] == b[3]) continue;
            if (a[1] == a[3] && b[1] == b[3]) continue;

            for (int k = j + 1; k < A * B; k++) {
                a[4] = k / B;
                b[4] = k % B;
                if (a[0] == a[4] && b[0] == b[4]) continue;
                if (a[1] == a[4] && b[1] == b[4]) continue;

                if (flush() && straight()) {
                    res[0]++;
                } else if (one(4)) {
                    res[1]++;
                } else if (two(3, 2)) {
                    res[2]++;
                } else if (flush()) {
                    res[3]++;
                } else if (straight()) {
                    res[4]++;
                } else if (one(3)) {
                    res[5]++;
                } else if (two(2, 2)) {
                    res[6]++;
                } else if (one(2)) {
                    res[7]++;
                } else {
                    res[8]++;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (i != 8) {
            printf("%d ", res[i]);
        } else {
            printf("%d\n", res[i]);
        }
    }
}
