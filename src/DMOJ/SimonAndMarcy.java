package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SimonAndMarcy
{

	public static void main(String[] args) throws Exception
	{
		int c = readInt();
		int m = readInt();

		int[][] dp = new int[m + 1][c + 1];
		int[][] val = new int[c + 1][2];
		for (int i = 1; i <= c; i++)
		{
			val[i][0] = readInt();
			val[i][1] = readInt();
		}

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= c; j++)
			{
				if (i - val[j][1] >= 0)
					dp[i][j] = Math.max(dp[i][j], dp[i - val[j][1]][j - 1] + val[j][0]);
				dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
			}

		System.out.println(dp[m][c]);
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
