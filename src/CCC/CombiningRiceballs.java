package CCC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CombiningRiceballs
{
	static int n, rice[], dp[][], largest = 0;

	static int f(int i, int j)
	{
		if (dp[i][j] != -1)
			return dp[i][j];
		if (i >= j)
			return dp[i][j] = 1;
		else
		{
			int ret = 0;
			int b = j;
			for (int a = i; a < j; a++)
			{
				while (b > i && rice[a] - rice[i - 1] > rice[j] - rice[b - 1])
					b--;
				if (rice[a] - rice[i - 1] == rice[j] - rice[b - 1])
					ret = Math.max(ret, f(i, a) * f(a + 1, b - 1) * f(b, j));
			}

			return dp[i][j] = ret;
		}
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		rice = new int[n + 1];
		dp = new int[n + 1][n + 1];

		for (int i = 1; i <= n; i++)
		{
			rice[i] = readInt();
			largest = Math.max(largest, rice[i]);
			rice[i] += rice[i - 1];
		}

		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				largest = Math.max(largest, f(i, j) * (rice[j] - rice[i - 1]));

		System.out.println(largest);
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
