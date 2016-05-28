package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class WinningAtSports
{
	static int dp[][], a, b, free, stress;

	static int play(int i, int j)
	{
		if (dp[i][j] != -1)
			return dp[i][j];

		int ret = 0;
		if (i != a)
			ret += play(i + 1, j);
		if (j != b)
			ret += play(i, j + 1);
		return dp[i][j] = ret % 1000000007;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		for (int c = 1; c <= n; c++)
		{
			String[] s = readLine().split("-");
			a = Integer.parseInt(s[0]);
			b = Integer.parseInt(s[1]);

			if (a == 0 || b == 0)
				System.out.printf("Case #%d: 1 1\n", c);
			else
			{
				free = stress = 0;

				dp = new int[a + 1][b + 1];
				for (int i = 0; i <= a; i++)
					for (int j = Math.min(i - 1, b); j >= 0; j--)
						dp[i][j] = -1;
				dp[a][b] = 1;
				free = play(1, 0);

				dp = new int[a + 1][b + 1];
				for (int i = 0; i <= a; i++)
					for (int j = i; j <= b; j++)
						dp[i][j] = -1;
				for (int i = 0; i <= a; i++)
					dp[i][b] = 1;
				stress = play(0, 1);

				System.out.printf("Case #%d: %d %d\n", c, free % 1000000007,
						stress % 1000000007);
			}
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