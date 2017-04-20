struct DisjointSetNode {
	int p, sz;
	DisjointSetNode(int p) : p(p), sz(1) {
	}
};

struct DisjointSet {
	int N;
	vector<DisjointSetNode> v;

	DisjointSet(int N) : N(N) {
		for (int i = 0; i <= N; i++) {
			v.push_back(DisjointSetNode(i));
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