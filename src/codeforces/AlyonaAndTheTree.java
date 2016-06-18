package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class AlyonaAndTheTree
{
	static class Edge
	{
		int u, d;

		Edge(int uu, int dd)
		{
			u = uu;
			d = dd;
		}
	}

	static int size(int x)
	{
		int ret = 1;
		for (Edge e : adj[x])
			ret += size(e.u);
		return size[x] = ret;
	}

	static int cut(int x, int d)
	{
		if (d > a[x])
			return size[x];

		int ret = 0;

		for (Edge e : adj[x])
			ret += cut(e.u, Math.max(d + e.d, e.d));

		return ret;
	}

	static int n, a[], size[];
	static long dist[];
	static ArrayList<Edge> adj[];

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		a = new int[n];
		size = new int[n];
		dist = new long[n];
		adj = new ArrayList[n];

		for (int i = 0; i < n; i++)
		{
			a[i] = readInt();
			adj[i] = new ArrayList<Edge>();
		}

		for (int i = 1; i < n; i++)
			adj[readInt() - 1].add(new Edge(i, readInt()));

		size(0);
		System.out.println(cut(0, 0));
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
