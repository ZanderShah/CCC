package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class IteratedLinearFunction
{
	// Mod everything
	static final int MOD = 1000000007;

	static long pow(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % MOD) * (x % MOD))
			if ((n >> i & 1) != 0)
				a = (a % MOD) * (x % MOD);
		return a % MOD;
	}

	public static void main(String[] args) throws Exception
	{
		long A = readInt(), B = readInt(), n = readLong(), x = readInt();
		System.out.println((x % MOD * pow(A, n) % MOD + B % MOD
				* (A == 1 ? n % MOD : (1 - pow(A, n)) * pow(1 - A, MOD - 2) % MOD)) % MOD);
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
