package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MMORPG2
{
	static ArrayList<Integer>[] adj;
	static long[][] ways;
	static int[] max;

	static long f(long x)
	{
		int ret = 1;
		for (int i = 2; i <= x; i++)
			ret *= x;
		return ret;
	}

	static void fill(int x, int l, int p)
	{
		max[p] = Math.max(max[p], l);
		ways[p][l]++;
		for (int i : adj[x])
			fill(i, l + 1, p);
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		adj = new ArrayList[n];

		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<Integer>();

		ArrayList<Integer> start = new ArrayList<Integer>();

		for (int i = 0, x; i < n; i++)
		{
			x = readInt() - 1;

			if (x != -1)
				adj[x].add(i);
			else
				start.add(i);
		}

		ways = new long[start.size()][n];
		max = new int[start.size()];

		for (int i = 0; i < start.size(); i++)
			fill(start.get(i), 0, i);

		for (int i = 0; i < start.size(); i++)
			for (int j = max[i]; j >= 0; j--)
				ways[i][j] = f(ways[i][j]) * (j != max[i] ? ways[i][j + 1] : 1);

		long ans = 0;

		for (int i = 0; i < start.size(); i++)
			for (int j = 0; j <= max[i]; j++)
			{
				long poss = ways[i][j];
				for (int k = 0; k < start.size(); k++)
					if (i != k)
						for (int l = 0; l <= max[k]; l++)
							poss *= ways[k][l] * f(start.size() - 1);
				ans += poss;
			}

		System.out.println(ans % 1000000007);
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
