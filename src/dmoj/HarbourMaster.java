package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HarbourMaster
{
	static int c, s, p, n;
	static int[][] val;
	static double best = 0;

	static void go(int x, int cc, int ss, int pp, int f)
	{
		if (f == 5 || x == n)
			best = Math.max(
					best,
					Math.min(
							1,
							Math.min(cc * 1.0 / c,
									Math.min(ss * 1.0 / s, pp * 1.0 / p))));
		else
		{
			go(x + 1, cc + val[x][0], ss + val[x][1], pp + val[x][2], f + 1);
			go(x + 1, cc, ss, pp, f);
		}
	}

	public static void main(String[] args) throws Exception
	{
		c = readInt();
		s = readInt();
		p = readInt();
		n = readInt();
		val = new int[n][3];

		for (int i = 0; i < n; i++)
		{
			val[i][0] = readInt();
			val[i][1] = readInt();
			val[i][2] = readInt();
		}

		go(0, 0, 0, 0, 0);
		System.out.println(Math.round(best * 1000) / 10.0);
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
