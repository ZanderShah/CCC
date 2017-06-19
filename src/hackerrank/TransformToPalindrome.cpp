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

const int MAXN = 1005;
int n, k, m, x, y, p[MAXN], dp[MAXN][MAXN];

int go(int i, int j) {
    if (j < i) {
        return 0;
    }
    if (i == j) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int ret = max(go(i + 1, j), go(i, j - 1));
    if (p[i] == p[j]) {
        ret = max(ret, go(i + 1, j - 1) + 2);
    }
    return dp[i][j] = ret;
}

int main() {
    scanf("%d %d %d", &n, &k, &m);
    DisjointSet ds(n);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        ds.merge(x, y);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        p[i] = ds.find(x);
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", go(0, m));
}
