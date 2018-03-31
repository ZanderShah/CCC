// SegTree used for DMOJ TouchingSegments

struct SegTree
{
	struct Node
    {
		int l, r, v, lazy;
	};

	int N;
	vector<Node> seg;

	SegTree(int N) : N(N), seg(3 * N)
    {
		build(1, 1, N);
	}

	void build(int i, int l, int r)
    {
		seg[i].l = l;
		seg[i].r = r;
		if (l == r)
        {
			// Initialize
			return;
		}
		int m = (l + r) >> 1;
		build(l(i), l, m);
		build(r(i), m + 1, r);
	}

	void update(int i, int l, int r, int v)
    {
		// Lazy Propogation
		if (seg[i].lazy != 0 && seg[i].l != seg[i].r)
        {
			seg[l(i)].v += seg[i].lazy;
			seg[l(i)].lazy += seg[i].lazy;
			seg[r(i)].v += seg[i].lazy;
			seg[r(i)].lazy += seg[i].lazy;
			seg[i].lazy = 0;
		}

		if (seg[i].l > r || seg[i].r < l)
			return;
		if (seg[i].l >= l && seg[i].r <= r)
        {
			// Update value and lazy
			seg[i].v += v;
			seg[i].lazy += v;
			return;
		}
		update(l(i), l, r, v);
		update(r(i), l, r, v);
		// PushUp
		seg[i].v = max(seg[l(i)].v, seg[r(i)].v);
	}
	void update(int l, int r, int v)
    {
		update(1, l, r, v);
	}

	int query(int i, int l, int r)
    {
		// Lazy Propogation
		if (seg[i].lazy != 0 && seg[i].l != seg[i].r)
        {
			seg[l(i)].v += seg[i].lazy;
			seg[l(i)].lazy += seg[i].lazy;
			seg[r(i)].v += seg[i].lazy;
			seg[r(i)].lazy += seg[i].lazy;
			seg[i].lazy = 0;
		}

		if (seg[i].l > r || seg[i].r < l)
        {
			// Empty
			return 0;
		}
		if (seg[i].l >= l && seg[i].r <= r)
        {
			// Value
			return seg[i].v;
		}
		// PushUp
		return max(query(l(i), l, r), query(r(i), l, r));
	}
	int query(int l, int r)
    {
		return query(1, l, r);
	}
};
