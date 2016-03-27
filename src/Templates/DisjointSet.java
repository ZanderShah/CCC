package Templates;

public class DisjointSet
{
	static Node v[];
	
	static class Node
	{
		int r, p;

		Node(int pp)
		{
			r = 0;
			p = pp;
		}
	}

	static int find(int x)
	{
		if (v[x].p != x)
			v[x].p = find(v[x].p);
		return v[x].p;
	}

	static void merge(int x, int y)
	{
		x = find(x);
		y = find(y);

		if (x == y)
			return;

		if (v[x].r < v[y].r)
			v[x].p = y;
		else if (v[x].r > v[y].r)
			v[y].p = x;
		else
		{
			v[y].p = x;
			v[x].r++;
		}
	}
}
