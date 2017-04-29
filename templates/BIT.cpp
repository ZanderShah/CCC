struct BIT {
	int N;
	vector<int> bit;

	BIT(int N) : N(N), bit(N + 1) {
	}

	void update(int x, int v) {
		for (; x <= N; x += x & -x) {
			bit[x] += v;
		}
	}

	int query(int x) {
		int ret = 0;
		for (; x; x -= x & -x) {
			ret += bit[x];
		}
		return ret;
	}
};

struct BIT {
	int N;
	vector<int> bit1, bit2;

	BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) {
	}

	void update(vector<int> &bit, int x, int v) {
		for (; x <= N; x += x & -x) {
			bit[x] += v;
		}
	}

	void update(int x, int y, int v) {
		update(bit1, x, v);
		update(bit1, y + 1, -v);
		update(bit2, x, v * (x - 1));
		update(bit2, y + 1, -v * y);
	}

	int query(vector<int> &bit, int x) {
		int ret = 0;
		for (; x; x -= x & -x) {
			ret += bit[x];
		}
		return ret;
	}

	int query(int x) {
		return query(bit1, x) * x - query(bit2, x);
	}

	int query(int x, int y) {
		return query(y) - query(x - 1);
	}
};
