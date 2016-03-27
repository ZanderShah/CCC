package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Fibonacci
{
	static long[][] m(long[][] a, long[][] b)
	{
		long[][] r = new long[2][2];
		r[0][0] = ((a[0][0] % 1000000007) * (b[0][0] % 1000000007) + (a[0][1] % 1000000007) * (b[1][0] % 1000000007)) % 1000000007;
		r[0][1] = ((a[0][0] % 1000000007) * (b[0][1] % 1000000007) + (a[0][1] % 1000000007) * (b[1][1] % 1000000007)) % 1000000007;
		r[1][0] = ((a[1][0] % 1000000007) * (b[0][0] % 1000000007) + (a[1][1] % 1000000007) * (b[1][0] % 1000000007)) % 1000000007;
		r[1][1] = ((a[1][0] % 1000000007) * (b[0][1] % 1000000007) + (a[1][1] % 1000000007) * (b[1][1] % 1000000007)) % 1000000007;
		return r;
	}

	public static void main(String[] args) throws Exception
	{
		BigInteger n = new BigInteger(next());

		long[][] a = { { 1, 1 }, { 1, 0 } };
		long[][] b = { { 1, 1 }, { 1, 0 } };

		for (; !n.equals(BigInteger.ZERO); n = n.shiftRight(1))
		{
			if (!n.and(BigInteger.ONE).equals(BigInteger.ZERO))
				a = m(a, b);
			b = m(b, b);
		}

		System.out.println(a[1][1]);
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
