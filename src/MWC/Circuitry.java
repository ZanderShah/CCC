package MWC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Circuitry
{
	static class Path implements Comparable<Path>
	{
		int a, b, l, i;

		Path(int aa, int bb, int ll, int ii)
		{
			a = aa;
			b = bb;
			l = ll;
			i = ii;
		}

		public int compareTo(Path p)
		{
			return l - p.l;
		}
	}

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

	static boolean dfs(int x)
	{
		if (x == goal)
			return true;

		vis[x] = true;

		for (Path p : adj[x])
		{
			int b;
			if (p.a == x)
				b = p.b;
			else
				b = p.a;

			if (!vis[b])
				if (dfs(b))
				{
					longest = Math.max(longest, length);
					if (p.l == length && length == longest)
					{
						useful[p.i] = 2;
						atLeastOne = true;
					}
					return true;
				}
		}

		return false;
	}

	static int n, m, goal, length, longest;
	static ArrayList<Path> edges = new ArrayList<Path>();
	static ArrayList<Path>[] adj;
	static boolean atLeastOne;
	static int[] useful;
	static boolean[] vis, empty;

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		m = readInt();
		v = new Node[n + 1];
		useful = new int[m];
		adj = new ArrayList[n + 1];
		empty = new boolean[n + 1];

		for (int i = 1; i <= n; i++)
		{
			v[i] = new Node(i);
			adj[i] = new ArrayList<Path>();
		}

		for (int i = 0; i < m; i++)
			edges.add(new Path(readInt(), readInt(), readInt(), i));

		Collections.sort(edges);
		for (Path p : edges)
			if (find(p.a) != find(p.b))
			{
				merge(p.a, p.b);
				useful[p.i] = 1;
				adj[p.a].add(p);
				adj[p.b].add(p);
			}

		for (Path p : edges)
			if (useful[p.i] == 0)
			{
				vis = empty;
				goal = p.b;
				length = p.l;
				longest = 0;
				atLeastOne = false;
				dfs(p.a);

				if (atLeastOne)
					useful[p.i] = 2;
			}

		for (int i : useful)
			if (i == 0)
				out.println("not useful");
			else if (i == 1)
				out.println("useful");
			else
				out.println("so so");
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
