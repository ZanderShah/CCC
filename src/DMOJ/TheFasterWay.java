package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class TheFasterWay
{

	public static void main(String[] args) throws Exception
	{
		long nn = readLong();
		BigInteger n = new BigInteger("" + nn);
		int k = readInt(), d = readInt();

		BigInteger p0 = BigInteger.ZERO;

		for (int i = d; i >= 0; i--)
		{
			BigInteger infected = new BigInteger("" + k);
			infected = infected.pow(i);
			BigInteger multi = n.divide(infected);
			p0 = p0.add(multi);
			n = n.subtract(infected.multiply(multi));
		}

		System.out.println(p0);
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
