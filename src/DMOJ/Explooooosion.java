package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Explooooosion
{
	static long power(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % 1000000007) * (x % 1000000007))
			if ((n >> i & 1) != 0)
				a = (a % 1000000007) * (x % 1000000007);
		return a % 1000000007;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = 1000000007;
		int[] p = new int[1001];
		for (int i = 0; i < n; i++)
			p[readInt()]++;

		long min = 0;
		for (int i = 2; i <= 1000; i++)
			min = (min + (p[i] != 0 ? power(i, p[i]) : 0)) % 1000000007;

		System.out.println(min);

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
