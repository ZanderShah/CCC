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

struct Node {
	Node *left, *right;
	int pre, suf, sum;
	Node(int v) : pre(v), suf(v), sum(v) {
		left = right = nullptr;
	}
	Node(Node *l, Node *r) : left(l), right(r) {
		pre = max(l->pre, l->sum + r->pre);
		suf = max(r->suf, r->sum + l->suf);
		sum = l->sum + r->sum;
	}
} *root[5 * MAXN];

int N, Q, val[MAXN], x, y, rev = 0;
char c;

Node *build(int l, int r) {
	if (l == r) {
		return new Node(val[l]);
	}
	int m = (l + r) >> 1;
	return new Node(build(l, m), build(m + 1, r));
}

Node *update(Node *cur, int l, int r, int x) {
	if (l <= x && x <= r) {
		if (l == r) {
			return new Node(val[l]);
		}
		int m = (l + r) >> 1;
		return new Node(update(cur->left, l, m, x), update(cur->right, m + 1, r, x));
	}
	return cur;
}

struct Query {
	int pre, suf, sum;
	bool empty;
	Query(int pre, int suf, int sum) : pre(pre), suf(suf), sum(sum), empty(0) {
	}
	Query(Node *cur) : pre(cur->pre), suf(cur->suf), sum(cur->sum), empty(0) {
	}
	Query() : pre(0), suf(0), sum(0), empty(1) {
	}
};

Query query(Node *cur, int cL, int cR, int l, int r) {
	if (cL > r || cR < l) {
		return Query();
	}
	if (cL >= l && cR <= r) {
		return Query(cur);
	}
	int m = (cL + cR) >> 1;

	Query lq = query(cur->left, cL, m, l, r), rq = query(cur->right, m + 1, cR, l, r);

	if (lq.empty || rq.empty) {
		return lq.empty ? rq : lq;
	}

	return Query(max(lq.pre, lq.sum + rq.pre), max(rq.suf, rq.sum + lq.suf), lq.sum + rq.sum);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &val[i]);
	}
	root[0] = build(1, N);

	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf(" %c", &c);
		switch(c) {
		case 'U':
			scanf("%d %d", &x, &y);
			val[x] = y;
			++rev;
			root[rev] = update(root[rev - 1], 1, N, x);
			break;
		case 'G':
			scanf("%d", &x);
			root[++rev] = root[x];
			break;
		case 'P':
			scanf("%d %d", &x, &y);
			printf("%d\n", query(root[rev], 1, N, x, y).pre);
			break;
		case 'S':
			scanf("%d %d", &x, &y);
			printf("%d\n", query(root[rev], 1, N, x, y).suf);
			break;
		}
	}
}
