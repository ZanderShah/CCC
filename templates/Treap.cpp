struct TreapNode {
	int key, val, size, pri;
	TreapNode *left, *right;
	TreapNode(int val, int key) : key(key), val(val), size(1) {
		left = right = nullptr;
		pri = rand() * 65536 + rand();
	}
	TreapNode(int val) : key(val), val(val), size(1) {
		left = right = nullptr;
		pri = rand() * 65536 + rand();
	}
};

struct Treap {
	TreapNode* root;

	Treap() {
		root = nullptr;
	}
	static int size(TreapNode *cur) {
		return cur != nullptr ? cur->size : 0;
	}
	static void update(TreapNode *cur) {
		if (nullptr == cur) {
			return;
		}
		cur->size = 1 + size(cur->left) + size(cur->right);
	}

	static TreapNode* merge(TreapNode *l, TreapNode *r) {
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

	static pair<TreapNode*, TreapNode*> split(TreapNode *cur, int key) {
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

	bool contains(TreapNode *cur, int key) {
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
	bool contains(int val) {
		return contains(root, val);
	}

	void insert(int val) {
		assert(!contains(val));
		auto p = split(root, val);
		root = merge(p.x, merge(new TreapNode(val), p.y));
	}

	void remove(int val) {
		assert(contains(val));
		auto p = split(root, val);
		root = merge(p.x, p.y);
	}

	int kthSmallest(TreapNode *cur, int k) {
		int leftSize = size(cur->left);

		if (leftSize + 1 == k) {
			return cur->val;
		} else if (leftSize + 1 > k) {
			return kthSmallest(cur->left, k);
		} else {
			return kthSmallest(cur->right, k - leftSize - 1);
		}
	}
	int kthSmallest(int k) {
		assert(k <= size(root));
		return kthSmallest(root, k);
	}

	int indexOf(TreapNode *cur, int key) {
		int leftSize = size(cur->left);

		if (key < cur->key) {
			return indexOf(cur->left, key);
		} else if (key > cur->key) {
			return leftSize + 1 + indexOf(cur->right, key);
		} else if (contains(cur->left, key)) {
			return indexOf(cur->left, key);
		}
		return leftSize + 1;
	}
	int indexOf(int x) {
		return contains(x) ? indexOf(root, x) : -1;
	}

	void traverse(TreapNode *cur) {
		if (nullptr == cur) {
			return;
		}
		traverse(cur->left);
		printf("%d ", cur->val);
		traverse(cur->right);
	}
	void traverse() {
		traverse(root);
	}
};
