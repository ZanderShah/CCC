struct BIT {
	int N;
	vector<int> bit;

	BIT(int N) : N(N), bit(N + 1) {}

	void update(int x, int v) {
		for (; x <= N; x += x & -x)
			bit[x] += v;
	}

	int query(int x) {
		int ret = 0;
		for (; x; x -= x & -x)
			ret += bit[x];
		return ret;
	}
};
