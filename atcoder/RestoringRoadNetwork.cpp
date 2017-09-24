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

struct DisjointSet {
	struct Node {
		int p, sz;
		Node(int p) : p(p), sz(1) {
		}
	};

	int N;
	vector<Node> v;

	DisjointSet(int N) : N(N) {
		for (int i = 0; i <= N; i++) {
			v.pb(Node(i));
		}
	}
	int find(int x) {
		if (v[x].p != x) {
			v[x].p = find(v[x].p);
		}
		return v[x].p;
	}
	void merge(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) {
			return;
		}

		if (v[x].sz > v[y].sz) {
			v[x].sz += v[y].sz;
			v[y].p = x;
		} else {
			v[y].sz += v[x].sz;
			v[x].p = y;
		}
	}
};

int N, A[305][305], B[305][305];
DisjointSet ds(305);
vector<pii> e;
ll cost;

bool c(pii x, pii y) {
    return A[x.x][x.y] < A[y.x][y.y];
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (A[i][k] > A[i][j] + A[j][k]) {
                    printf("-1\n");
                    return 0;
                }
            }
            e.pb(pii(i, j));
        }
    }
	sort(e.begin(), e.end(), c);

	for (int i = 0; i < e.size(); i++) {
        // Check if condition is already satisfied
        bool vis = 1;
        for (int j = 1; j <= N; j++) {
            if (j == e[i].x || j == e[i].y) continue;
            if (A[e[i].x][j] + A[j][e[i].y] == A[e[i].x][e[i].y]) {
                vis = 0;
            }
        }
        cost += vis * A[e[i].x][e[i].y];
    }
    
    printf("%lld\n", cost / 2);
}
