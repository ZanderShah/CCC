package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

// [1 0]
// [0 1]

// [3 1]
// [1 3]
public class Plant
{
	static final int MOD = 1000000007;

	static long[][] multi(long[][] a, long[][] b)
	{
		long[][] r = new long[2][2];
		r[0][0] = ((a[0][0] * b[0][0] % MOD) + (a[0][1] * b[1][0] % MOD)) % MOD;
		r[0][1] = ((a[0][0] * b[0][1] % MOD) + (a[0][1] * b[1][1] % MOD)) % MOD;
		r[1][0] = ((a[1][0] * b[0][0] % MOD) + (a[1][1] * b[1][0] % MOD)) % MOD;
		r[1][1] = ((a[1][0] * b[0][1] % MOD) + (a[1][1] * b[1][1] % MOD)) % MOD;
		return r;
	}

	public static void main(String[] args) throws Exception
	{
		long n = readLong();
		long[][] t = { { 1, 0 }, { 0, 1 } };
		long[][] m = { { 3, 1 }, { 1, 3 } };

		for (int i = 0; i < 64; i++)
		{
			if ((1l << i & n) != 0)
				t = multi(t, m);
			m = multi(m, m);
		}

		System.out.println(t[0][0]);
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
