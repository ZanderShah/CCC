package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Postcard
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int m = readInt();
		char[][] p = new char[n][m];

		int u = n, l = m, d = -1, r = -1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				p[i][j] = readChar();
				if (p[i][j] == '*')
				{
					l = Math.min(l, j);
					r = Math.max(r, j);
					u = Math.min(u, i);
					d = Math.max(d, i);
				}
			}

		for (int i = u; i <= d; i++)
		{
			for (int j = l; j <= r; j++)
				System.out.print(p[i][j]);
			System.out.println();
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
