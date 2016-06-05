package fhc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class LazySort
{
	static boolean sortable(int l, int r, int a, int b)
	{
		while (l < r)
		{
			boolean unchanged = true;
			if (v[l] == a - 1)
			{
				a = v[l++];
				unchanged = false;
			}
			if (v[l] == b + 1)
			{
				b = v[l++];
				unchanged = false;
			}
			if (v[r] == a - 1)
			{
				a = v[r--];
				unchanged = false;
			}
			if (v[r] == b + 1)
			{
				b = v[r--];
				unchanged = false;
			}

			if (unchanged)
				return false;
		}

		return l >= r;
	}

	static int v[];

	public static void main(String[] args) throws Exception
	{
		int t = readInt();
		for (int c = 1; c <= t; c++)
		{
			int n = readInt();
			v = new int[n];
			for (int i = 0; i < n; i++)
				v[i] = readInt();

			System.out.printf("Case #%d: %s%n", c,
					(sortable(1, n - 1, v[0], v[0]) ||
							sortable(0, n - 2, v[n - 1], v[n - 1])
							? "yes" : "no"));
		}
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
