package MWC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Dolls
{
	static class Price implements Comparable<Price>
	{
		int p, f;

		Price(int pp)
		{
			p = pp;
			f = 0;
		}

		public int compareTo(Price x)
		{
			return f - x.f;
		}
	}

	public static void main(String[] args) throws Exception
	{
		Price[] dolls = new Price[101];
		for (int i = 0; i < 101; i++)
			dolls[i] = new Price(i);

		int n = readInt();
		for (int i = 0; i < n; i++)
			dolls[readInt()].f++;

		Arrays.sort(dolls);
		int d = 101, u = -1;

		int l = 0;
		while (dolls[l].f == 0)
			l++;

		for (int i = l; i < 101 && dolls[i].f == dolls[l].f; i++)
			d = Math.min(d, dolls[i].p);

		for (int i = 100; i >= 0 && dolls[i].f == dolls[100].f; i--)
			u = Math.max(u, dolls[i].p);
		
		System.out.println(Math.abs(u - d));
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
