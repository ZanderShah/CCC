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

int N, Q, x, y, v;
char c, s;
Treap t;
umii timeToLabel, labelToTime;

struct Treap {
	struct Node {
		int key, val, size, pri;
		Node *left, *right;
		Node(int val, int key) : key(key), val(val), size(1) {
			left = right = nullptr;
			pri = rand() * 65536 + rand();
		}
		Node(int key) : key(key), val(key), size(1) {
			left = right = nullptr;
			pri = rand() * 65536 + rand();
		}
	} *root;

	Treap() {
		root = nullptr;
	}
	static int size(Node *cur) {
		return cur != nullptr ? cur->size : 0;
	}
	static void update(Node *cur) {
		if (nullptr == cur) {
			return;
		}
		cur->size = 1 + size(cur->left) + size(cur->right);
	}

	static Node* merge(Node *l, Node *r) {
		if (nullptr == l) {
			return r;
		}
		if (nullptr == r) {
			return l;
		}

		if (l->pri > r->pri) {
			l->right = merge(l->right, r);
			update(l);
			return l;
		} else {
			r->left = merge(l, r->left);
			update(r);
			return r;
		}
	}

	static pair<Node*, Node*> split(Node *cur, int key) {
		if (nullptr == cur) {
			return mp(nullptr, nullptr);
		}

		if (key < cur->key) {
			auto ret = split(cur->left, key);
			cur->left = ret.y;
			ret.y = cur;
			update(ret.x);
			update(ret.y);
			return ret;
		} else if (key > cur->key) {
			auto ret = split(cur->right, key);
			cur->right = ret.x;
			ret.x = cur;
			update(ret.x);
			update(ret.y);
			return ret;
		} else {
			return mp(cur->left, cur->right);
		}
	}

	Node *find(Node *cur, int key) {
		if (nullptr == cur) {
			return nullptr;
		}
		if (key < cur->key) {
			return find(cur->left, key);
		} else if (key > cur->key) {
			return find(cur->right, key);
		}
		return cur;
	}
	Node *find(int key) {
		assert(contains(root, key));
		return find(root, key);
	}

	bool contains(Node *cur, int key) {
		if (nullptr == cur) {
			return 0;
		}
		if (key < cur->key) {
			return contains(cur->left, key);
		} else if (key > cur->key) {
			return contains(cur->right, key);
		}
		return 1;
	}
	bool contains(int key) {
		return contains(root, key);
	}

	void insert(int key, int val) {
		assert(!contains(key));
		auto p = split(root, key);
		root = merge(p.x, merge(new Node(key, val), p.y));
	}

	void remove(int key) {
		assert(contains(key));
		auto p = split(root, key);
		root = merge(p.x, p.y);
	}
};

int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y);
		t.insert(y);
		timeToLabel[x] = y;
		labelToTime[y] = x;
	}
	for (int i = 0; i < Q; i++) {
		scanf(" %c", &c);
		if (c == 'T') {
			// Change time
			scanf("%d %d", &x, &y);
			int l = timeToLabel[x];
			timeToLabel[l] = y;
		} else if (c == 'L') {
			scanf("%d %d", &x, &y);
			// Update label
			t.remove(timeToLabel[x]);
			t.insert(y);
			timeToLabel[x] = y;
			labelToTime[y] = x;
		} else if (c == 'F') {
			scanf(" %c %d", &s, &v);
		} else {
			scanf("%d", &x);
		}
	}
}
