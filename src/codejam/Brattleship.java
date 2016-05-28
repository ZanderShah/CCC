package codejam;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Brattleship
{

	public static void main(String[] args) throws Exception
	{
		out = new PrintWriter(new FileWriter("out.txt"));
		int t = readInt();
		for (int l = 1; l <= t; l++)
		{
			int r = readInt(), c = readInt(), w = readInt();
			int m = r * (c / w) + (w - 1);
			if (c % w != 0)
				m++;

			out.printf("Case #%d: %d\n", l, m);
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out;
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
