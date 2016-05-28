package ecoo;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TourDeForce
{
	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 10; t++)
		{
			int n = readInt();
			int[] val = new int[n];
			int[][] dp = new int[n][5];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < 5; j++)
					dp[i][j] = -1;
			int sum = 0;

			for (int i = 0; i < n; i++)
			{
				sum += readInt();
				val[i] = readInt();
			}

			dp[0][1] = val[0];
			for (int i = 1; i < n; i++)
				for (int j = 0; j < 5; j++)
				{
					for (int q = 0; q < 5; q++)
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][q] - 1);
					for (int q = 0; q < j; q++)
						dp[i][j] = Math.max(dp[i][j], dp[i - 1][q] + val[i]);
				}

			System.out.println(dp[n - 1][4] + sum);
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}
}
