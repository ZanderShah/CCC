package cco;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DataStructure
{
	static class Point implements Comparable<Point>
	{
		long r, c;

		Point(long rr, long cc)
		{
			r = rr;
			c = cc;
		}

		@Override
		public int compareTo(Point p)
		{
			if (c == p.c)
				return ((Long) p.r).compareTo(r);
			return ((Long) c).compareTo(p.c);
		}
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = readInt();
		Point[] p = new Point[m + 1];
		for (int i = 0; i < m; i++)
			p[i] = new Point(n - readInt() + 1, readInt());
		p[m] = new Point(n + 1, n + 1);
		Arrays.sort(p);

		long ans = 0;
		long height = p[0].r;
		long column = p[0].c;

		for (int i = 1; i <= m; i++)
			if (p[i].c != p[i - 1].c)
			{
				long newHeight = height - (p[i].c - column);

				if (newHeight < p[i].r)
				{
					ans += (newHeight < 1 ? height * (height + 1) / 2
							: (height - newHeight) * (height + newHeight + 1)
									/ 2);
					height = p[i].r;
					column = p[i].c;
				}
			}

		System.out.println(ans);
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