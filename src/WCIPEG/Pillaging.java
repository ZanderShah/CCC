package WCIPEG;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Pillaging
{
	static class Village implements Comparable<Village>
	{
		int p, x, s;

		Village(int pp, int xx, int ss)
		{
			p = pp;
			x = xx;
			s = ss;
		}

		public int compareTo(Village v)
		{
			return p - v.p;
		}
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int t = readInt();
		Village[] v = new Village[n];
		long[] a = new long[n + 1];
		long[] b = new long[n + 1];
		b[0] = -t;
		for (int i = 0; i < n; i++)
			v[i] = new Village(readInt(), readInt(), readInt());
		Arrays.sort(v);

		for (int i = 1; i <= n; i++)
		{
			a[i] = a[i - 1];
			b[i] = b[i - 1];
			if (v[i - 1].s == 0)
				a[i] = Math.max(a[i] + v[i - 1].x, b[i] - t + v[i - 1].x);
			else
				b[i] = Math.max(b[i] + v[i - 1].x, a[i] - t + v[i - 1].x);
		}

		System.out.println(Math.max(a[n], b[n]));
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
