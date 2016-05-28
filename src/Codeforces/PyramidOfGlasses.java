package Codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PyramidOfGlasses
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), t = readInt();
		double[][] p = new double[n][n];

		for (int r = 0; r < t; r++)
		{
			p[0][0]++;

			for (int i = 0; i < n; i++)
				for (int j = 0; j <= i; j++)
					if (p[i][j] > 1 && i + 1 < n)
					{
						double f = p[i][j] - 1;
						p[i][j] = 1;
						p[i + 1][j] += f / 2;
						p[i + 1][j + 1] += f / 2;
					}
		}

		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				if (p[i][j] >= 1)
					c++;
		System.out.println(c);
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
