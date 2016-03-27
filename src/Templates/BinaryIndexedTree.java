package Templates;

public class BinaryIndexedTree
{
	static int bit[], n;
	
	static void pointUpdate(int x, long v)
	{
		for (; x <= 100000; x += (x & (-x)))
			bit[x] += v;
	}

	static void rangeUpdate(int l, int r)
	{
		while (l <= n || r <= n)
		{
			if (l <= n)
			{
				bit[l]--;
				l += (l & (-l));
			}
			if (r <= n)
			{
				bit[r]++;
				r += (r & (-r));
			}
		}
	}

	static long rangeQuery(int l, int r)
	{
		long ans = 0;
		while (l > 0 || r > 0)
		{
			if (l > 0)
			{
				ans -= bit[l];
				l -= (l & (-l));
			}
			if (r > 0)
			{
				ans += bit[r];
				r -= (r & (-r));
			}
		}

		return ans;
	}

	static int pointQuery(int x)
	{
		int ans = 0;
		for (; x > 0; x -= (x & (-x)))
			ans += bit[x];
		return ans;
	}
}
