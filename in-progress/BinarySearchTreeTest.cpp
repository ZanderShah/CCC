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
	int v, sz, pri;
	Node *l, *r;
} *root;

int size(Node *x) {
	return x == nullptr ? 0 : x->sz;
}

bool has(Node *x, int v) {
	if (x == nullptr) {
		return 0;
	}
	if (v < x->v) {
		return has(x->l, v);
	} else if (v > x->v) {
		return has(x->r, v);
	}
	return 1;
}

Node *rl(Node *x) {
	Node *r = x->r;
	x->r = r->l;
	r->l = x;
	x->sz = 1 + size(x->l) + size(x->r);
	return r;
}

Node *rr(Node *x) {
	Node *l = x->l;
	x->l = l->r;
	l->r = x;
	x->sz = 1 + size(x->l) + size(x->r);
	return l;
}

Node *add(Node *x, int v) {
	if (x == nullptr) {
		return new Node {v, 1, rand(), nullptr, nullptr};
	}
	if (v < x->v) {
		x->l = add(x->l, v);
		if (x->pri < x->l->pri) {
			x = rr(x);
		}
	} else {
		x->r = add(x->r, v);
		if (x->pri < x->r->pri) {
			x = rl(x);
		}
	}
	x->sz = 1 + size(x->l) + size(x->r);
	return x;
}

Node *large(Node *x) {
	if (x->r == nullptr) {
		return x;
	}
	return large(x->r);
}

Node *rem(Node *x, int v) {
	if (v == x->v) {
		if (x->l == nullptr || x->r == nullptr) {
			Node *c = x->l ? x->l : x->r;
			if (c == root) {
				root = nullptr;
			}
			delete x;
			x = nullptr;
			return c;
		} else {
			Node *c = large(x->l);
			x->v = c->v;
			rem(x->l, c->v);
			return x;
		}
	} else if (v < x->v) {
		x->sz--;
		x->l = rem(x->l, v);
		return x;
	} else {
		x->sz--;
		x->r = rem(x->r, v);
		return x;
	}
}

int query(Node *x, int sz) {
	if (sz <= 0 || size(x) < sz) {
		return -1;
	}
	if (sz <= size(x->l)) {
		return query(x->l, sz);
	} else if (sz == size(x->l) + 1) {
		return x->v;
	} else {
		return query(x->r, sz - (size(x->l) + 1));
	}
}

void print(Node *x) {
	if (x == nullptr) {
		return;
	}
	print(x->l);
	printf("%d ", x->v);
	print(x->r);
}

int N, M, x, last = 0, up;
char c;

int main() {
	srand(time(NULL));

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		root = add(root, x);
	}
	for (int i = 0; i < M; i++) {
		scanf(" %c %d", &c, &x);
		x ^= last;
		switch (c) {
		case 'I':
			root = add(root, x);
			break;
		case 'R':
			if (has(root, x)) {
				root = rem(root, x);
			}
			break;
		case 'S':
			last = query(root, x);
			printf("%d\n", last);
			break;
		case 'L':
			last = has(root, x) ? last : -1;
			if (last == -1) {
				printf("-1\n");
				break;
			}
			last = 1;
			up = size(root);

			while (last <= up) {
				if (query(root, (last + up) / 2) < x) {
					last = (last + up) / 2 + 1;
				} else {
					up = (last + up) / 2 - 1;
				}
			}

			printf("%d\n", last);
			break;
		}
	}
	print(root);
}
