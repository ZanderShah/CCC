package cco;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class EasyProblem
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt(), best = 0;;
		int[] dp = new int[n], last = new int[30], newLast = new int[30];
		
		for (int i = 0; i < 30; i++)
			last[i] = newLast[i] = -1;
		
		for (int i = 0, a; i < n; i++) {
			a = readInt();
			dp[i] = 1;

			for (int j = 0; a != 0; a >>= 1, j++)
				if ((a & 1) != 0) {
					if (last[j] != -1)
						dp[i] = Math.max(dp[i], dp[last[j]] + 1);
					newLast[j] = i;
				}

			for (int j = 0; j < 30; j++)
				last[j] = newLast[j];
			best = Math.max(best, dp[i]);
		}
		
		System.out.println(best);
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
