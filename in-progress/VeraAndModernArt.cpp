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

const int MAXN = 2e5 + 5;

ll x, y, r, c;
int N, Q, v;

struct NodeY {
	int v;
	NodeY *l, *r;
};

struct NodeX {
	NodeX *l, *r;
	NodeY *y;
} *root;

void insertY(NodeY *n, ll y, int v) {
	if (y == 1) {
		n->v += v;
		return;
	}
	if (y & 1) {
		if (n->r == nullptr) {
			n->r = new NodeY;
		}
		insertY(n->r, y >> 1, v);
	} else {
		if (n->l == nullptr) {
			n->l = new NodeY;
		}
		insertY(n->l, y >> 1, v);
	}
}

void insertX(NodeX *n, ll x, ll y, int v) {
	if (x == 1) {
		if (n->y == nullptr) {
			n->y = new NodeY;
		}
		insertY(n->y, y, v);
		return;
	}
	if (x & 1) {
		if (n->r == nullptr) {
			n->r = new NodeX;
		}
		insertX(n->r, x >> 1, y, v);
	} else {
		if (n->l == nullptr) {
			n->l = new NodeX;
		}
		insertX(n->l, x >> 1, y, v);
	}
}

int queryY(NodeY *n, ll y) {
	if (n == nullptr) {
		return 0;
	}

	if (y == 1) {
		return n->v;
	}
	if (y & 1) {
		return queryY(n->r, y >> 1) + n->v;
	}
	return queryY(n->l, y >> 1) + n->v;
}

int queryX(NodeX *n, ll x, ll y) {
	if (n == nullptr) {
		return 0;
	}

	if (x == 1) {
		return queryY(n->y, y);
	}
	if (x & 1) {
		return queryX(n->r, x >> 1, y) + queryY(n->y, y);
	}
	return queryX(n->l, x >> 1, y) + queryY(n->y, y);
}

int main() {
	scan(N); scan(Q);
	root = new NodeX;
	for (int i = 0; i < N; i++) {
		scan(x); scan(y); scan(v);
		insertX(root, x, y, v);
	}
	for (int q = 0; q < Q; q++) {
		scan(r); scan(c);
		printf("%d\n", queryX(root, r, c));
	}
}
