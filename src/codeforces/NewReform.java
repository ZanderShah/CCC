package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class NewReform
{
	static boolean go(int x, int p)
	{
		if (vis[x])
			return true;

		vis[x] = true;
		boolean ret = false;

		for (int i : adj[x])
			if (i != p && go(i, x))
				ret = true;

		return ret;
	}

	static int n;
	static boolean[] vis;
	static ArrayList<Integer>[] adj;

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		int m = readInt();

		adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<Integer>();

		vis = new boolean[n];

		for (int i = 0; i < m; i++)
		{
			int a = readInt() - 1, b = readInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
			if (!vis[i] && !go(i, -1))
				ans++;
		System.out.println(ans);
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
