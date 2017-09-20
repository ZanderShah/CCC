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
#include <unordered_set>
#include <map>
#include <bitset>
#include <cstdio>
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
typedef unordered_map<int, int> umii;

struct Node {
	int v, id, tsz, ssz, par;
	Node *l, *r;
} *v[100005];

// Treap

int size(Node *x) {
	return x == nullptr ? 0 : x->tsz;
}

Node *add(Node *x, int val, int id) {
	if (x == nullptr) {
		return new Node {val, id, 1, 1, id, nullptr, nullptr};
	}
	if (val < x->v) {
		x->l = add(x->l, val, id);
	} else {
		x->r = add(x->r, val, id);
	}
	x->tsz = 1 + size(x->l) + size(x->r);
	return x;
}

int query(Node *x, int sz) {
	if (size(x) < sz) {
		return -1;
	}
	if (sz <= size(x->l)) {
		return query(x->l, sz);
	} else if (sz == size(x->l) + 1) {
		return x->id;
	} else {
		return query(x->r, sz - (size(x->l) + 1));
	}
}

// Insert all elements from x into y
void fullAdd(Node *x, Node *y) {
	if (x == nullptr) {
		return;
	}
	fullAdd(x->l, y);
	fullAdd(x->r, y);
	add(y, x->v, x->id);
}

// Disjoint-set

int find(int x) {
	if (v[x]->par != x) {
		return v[x]->par = find(v[x]->par);
	}
	return v[x]->par;
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	if (v[x]->ssz < v[y]->ssz) {
		v[y]->ssz += v[x]->ssz;
		v[x]->par = y;
		fullAdd(v[x], v[y]);
	} else {
		v[x]->ssz += v[y]->ssz;
		v[y]->par = x;
		fullAdd(v[y], v[x]);
	}
}

int N, M, Q, r, x, y;
char c;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &r);
		v[i] = add(nullptr, r, i);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		merge(x, y);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf(" %c %d %d", &c, &x, &y);
		if (c == 'B') {
			merge(x, y);
		} else {
			printf("%d\n", query(v[find(x)], y));
		}
	}
}
