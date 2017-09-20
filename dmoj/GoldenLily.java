package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class GoldenLily
{
	// If you're reading this I apologize for how messy it is
	public static void main(String[] args) throws Exception
	{
		int c = readInt();
		int r = readInt();

		int[][] w = new int[r][c];
		int[][] dp = new int[r][c];

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				w[i][j] = readInt();
				dp[i][j] = 1 << 30;
			}

		int eL = readInt();
		int eD = readInt();

		dp[0][0] = w[0][0];
		for (int i = 1; i < c; i++)
			dp[0][i] = w[0][i] + dp[0][i - 1];

		for (int i = 1; i < r; i++)
		{
			dp[i][0] = Math.min(dp[i][0], dp[i - 1][0] + w[i][0]);
			dp[i][c - 1] = Math.min(dp[i][c - 1], dp[i - 1][c - 1]
					+ w[i][c - 1]);

			for (int j = 1; j < c - 1; j++)
			{
				dp[i][j] = Math.min(
						dp[i][j],
						Math.min(dp[i][j - 1],
								Math.min(dp[i][j + 1], dp[i - 1][j]))
								+ w[i][j]);
			}
			for (int j = c - 2; j >= 1; j--)
			{
				dp[i][j] = Math.min(
						dp[i][j],
						Math.min(dp[i][j - 1],
								Math.min(dp[i][j + 1], dp[i - 1][j]))
								+ w[i][j]);
			}

			if (1 < c)
				dp[i][0] = Math.min(dp[i][0], dp[i][1] + w[i][0]);
			if (c - 2 >= 0)
				dp[i][c - 1] = Math.min(dp[i][c - 1], dp[i][c - 2]
						+ w[i][c - 1]);
		}

		System.out.println(dp[eD][eL]);
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
