package ccc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Golf
{

	public static void main(String[] args) throws Exception
	{
		int m = readInt();
		int n = readInt();
		int[] v = new int[n];
		for (int i = 0; i < n; i++)
			v[i] = readInt();
		int[] dp = new int[m + 1];
		for (int i = 0; i < n; i++)
			dp[v[i]] = 1;
		for (int i = 0; i < n; i++)
			for (int j = v[i]; j <= m; j++)
				if (dp[j - v[i]] != 0)
					if (dp[j] == 0)
						dp[j] = dp[j - v[i]] + 1;
					else
						dp[j] = Math.min(dp[j], dp[j - v[i]] + 1);

		if (dp[m] == 0)
			System.out.println("Roberta acknowledges defeat.");
		else
			System.out.printf("Roberta wins in %d strokes.", dp[m]);
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
