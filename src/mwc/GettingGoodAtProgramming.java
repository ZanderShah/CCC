package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class GettingGoodAtProgramming
{
	static int n, t, info[][][], dp[][];

	static int solve(int x, int d)
	{
		if (x >= n || d > t)
			return 0;
		else if (dp[x][d] != -1)
			return dp[x][d];
		else
		{
			int best = 0;
			for (int i = 0; i < 100 && info[x][i][0] != 0; i++)
				if (d + info[x][i][0] <= t)
					best = Math.max(best, solve(x + 1, d + info[x][i][0]) + info[x][i][1]);
			best = Math.max(best, solve(x + 1, d));
			return dp[x][d] = best;
		}
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		t = readInt();
		info = new int[n][100][2];
		dp = new int[n][t + 1];

		for (int i = 0, l; i < n; i++)
		{
			Arrays.fill(dp[i], -1);
			l = readInt();
			for (int j = 0; j < l; j++)
			{
				info[i][j][0] = readInt();
				info[i][j][1] = readInt();

				if (j != 0)
				{
					info[i][j][0] += info[i][j - 1][0];
					info[i][j][1] += info[i][j - 1][1];
				}
			}
		}

		System.out.println(solve(0, 0));
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
