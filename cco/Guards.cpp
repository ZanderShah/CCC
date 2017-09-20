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

const int MAXN = 2e6 + 5;

int N, M, cur, type, switches, x;
bool t[MAXN], start[MAXN];
set<int> out[MAXN], inc[MAXN];
set<pii> m;
deque<int> dq;

int solve(int tt) {
    for (auto it = m.begin(); it != m.end(); it++) {
        int a = it->x, b = it->y;
		out[a].insert(b);
        inc[b].insert(a);
    }

    for (int i = 0; i < N; i++) {
        if (!start[i]) continue;
        if (t[i]) {
            dq.pb(i);
        } else {
            dq.push_front(i);
        }
    }

    int cur = 0;
    int type = tt;

    while (!dq.empty()) {
        if (type == 0) {
            x = dq.front();
            dq.pop_front();
        } else {
            x = dq.back();
            dq.pop_back();
        }

        if (type != t[x]) {
            cur++;
            type = t[x];
        }

        for (auto it = out[x].begin(); it != out[x].end(); it++) {
            inc[*it].erase(x);
            if (!inc[*it].empty()) continue;

            if (t[*it]) {
                dq.pb(*it);
            } else {
                dq.push_front(*it);
            }
        }
    }

    return cur;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &t[i]);
		start[i] = 1;
	}
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d %d", &a, &b);
        m.insert(mp(a, b));
		start[b] = 0;
	}

    printf("%d\n", min(solve(0), solve(1)));
}
