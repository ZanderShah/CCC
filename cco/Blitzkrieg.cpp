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
#include <cassert>
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

const int MAXN = 105;

int N, M, D, A, B;
ll K;
vector<int> cost[MAXN][MAXN];

void print(vector<vector<ll> > v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%lld ", v[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

vector<vector<ll> > multiply(vector<vector<ll> > a, vector<vector<ll> > b) {
	vector<vector<ll> > c;
	c.resize(N);
	for (int i = 0; i < N; i++) {
		c[i].resize(N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				c[i][j] = min(K, c[i][j] + a[i][k] * b[k][j]);
			}
		}
	}

	return c;
}

int count(int a, int b, int w) {
	for (int i = 0; i < cost[a][b].size(); i++) {
		if (cost[a][b][i] > w) {
			return i;
		}
	}
	return cost[a][b].size();
}

bool valid(int w) {
	if (D == 0) {
		return A == B && count(A, B, w) >= K;
	}

	vector<vector<ll> > ret, mult;
	ret.resize(N);
	mult.resize(N);
	for (int i = 0; i < N; i++) {
		ret[i].resize(N);
		mult[i].resize(N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mult[i][j] = count(i, j, w);
		}
		ret[i][i] = 1;
	}

	for (int i = 0; i < 31; i++) {
		if (D >> i & 1) {
			ret = multiply(ret, mult);
		}
		mult = multiply(mult, mult);
	}

	return ret[A][B] >= K;
}

int main() {
	scanf("%d %d %d %lld %d %d", &N, &M, &D, &K, &A, &B);
	for (int i = 0, x, y, w; i < M; i++) {
		scanf("%d %d %d", &x, &y, &w);
		cost[x][y].pb(w);
		if (x != y) {
			cost[y][x].pb(w);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sort(cost[i][j].begin(), cost[i][j].end());
		}
	}

    if (!valid(1e9)) {
        printf("-1\n");
        return 0;
    }

	int lo = 0, hi = 1e9 + 5, mid = (lo + hi) >> 1;
	while (lo <= hi) {
		if (!valid(mid)) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
		mid = (lo + hi) >> 1;
	}
	printf("%d\n", lo);
}
