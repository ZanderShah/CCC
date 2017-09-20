package mwc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Breadwinners
{
	static boolean isPrime(int x)
	{
		for (int i = 2; i * i <= x; i++)
			if (x % i == 0)
				return false;
		return true;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int[] c = new int[100001];

		int small = 2;
		c[0] = -1;
		c[1] = -1;
		c[2] = -1;

		for (int i = 3; i <= 100000; i++)
		{
			c[i] = small;
			if (isPrime(i))
				small = i;
		}

		for (int i = 0, x; i < n; i++)
		{
			x = readInt();
			if (c[x] == -1)
				System.out.println("no can do");
			else
				System.out.println(c[x]);
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
