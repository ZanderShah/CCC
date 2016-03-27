package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class LineGraph
{
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
	
	static class Path implements Comparable<Path>
	{
		int a, b, w;
		Path(int aa, int bb, int ww)
		{
			a = aa;
			b = bb;
			w = ww;
		}
		
		public int compareTo(Path p)
		{
			return w - p.w;
		}
	}
	
	static Node[] v;

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int k = readInt();
		v = new Node[n + 1];
		for (int i = 0; i <= n; i++)
			v[i] = new Node(i);
		ArrayList<Path> paths = new ArrayList<Path>();
		
		for (int i = 1; i <= n - 1; i++)
		{
			int w = readInt();
			if (i + k <= n && find(i) != find(i + k))
				merge(i, i + k);
			paths.add(new Path(i, i + 1, w));
		}
		
		Collections.sort(paths);
		int cost = 0;
		
		for (Path p : paths)
			if (find(p.a) != find(p.b))
			{
				merge(p.a, p.b);
				cost += p.w;
			}
		
		System.out.println(cost);
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
