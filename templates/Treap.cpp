struct Treap {
	struct Node {
		int key, val, size, pri;
		Node *left, *right;
		Node(int val, int key) : key(key), val(val), size(1) {
			left = right = nullptr;
			pri = rand() * 65536 + rand();
		}
		Node(int val) : key(val), val(val), size(1) {
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
	bool contains(int val) {
		return contains(root, val);
	}

	void insert(int val) {
		assert(!contains(val));
		auto p = split(root, val);
		root = merge(p.x, merge(new Node(val), p.y));
	}

	void remove(int val) {
		assert(contains(val));
		auto p = split(root, val);
		root = merge(p.x, p.y);
	}

	int kthSmallest(Node *cur, int k) {
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

	int indexOf(Node *cur, int key) {
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

	void traverse(Node *cur) {
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
