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

const int MAXN = 1e5 + 5;

struct Q {
    int i, x;
    char c;

	bool operator <(const Q& q) const {
        return i > q.i;
	}
};

int N, M, s[26];

char c, f = '$';
int x, y, in[26];

string r = "";

priority_queue<Q> q[26];
priority_queue<Q> pq;

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf(" %c %d %d", &c, &x, &y);
        q[c - 'a'].push(Q{y, x, c});
        // pq.push(Q{c, y, x}});
    }

    for (int i = 0; i < N; ) {
        for (int j = 0; j < 26; j++) {
            if (in[j] > i) continue;
            if (q[j].empty()) {
                f = j + 'a';
                continue;
            }
            pq.push(q[j].top());
            in[j] = q[j].top().i;
            q[j].pop();
        }
        
        if (pq.empty()) {
            if (f == '$') {
                cout << -1 << endl;
                return 0;
            }
            r += f;
            s[f - 'a']++;
            i++;
            continue;
        }

        c = pq.top().c;
        x = pq.top().x - s[c - 'a'];
        
        if (x != 0 && i + x > pq.top().i || x < 0) {
            // cout << i << " " << x << " " << pq.top().i << " " << c << endl;
            // cout << pq.top().x << endl;
            // cout << r << endl;
            cout << -1 << endl;
            return 0;
        }

        if (x <= 1) {
            pq.pop();
        }
        if (x == 0) {
            continue;
        }

        r += c;
        s[c - 'a']++;
        i++;
    }

    while (!pq.empty()) {
        x = pq.top().x - s[c - 'a'];
        pq.pop();
        if (x != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (q[i].empty()) continue;

        while (!q[i].empty()) {
            x = q[i].top().x - s[i];
            q[i].pop();
            if (x != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    
    cout << r << endl;
}