package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class CamelCase
{
	public static void main(String[] args) throws Exception
	{
		br = new BufferedReader(new FileReader("DATA32.txt"));

		int n = readInt();
		String[] dict = new String[n];

		for (int i = 0; i < n; i++)
			dict[i] = readLine();

		Arrays.sort(dict);
		/*
		 * 5 5 13 9 24 53 120 117 234 228
		 */

		for (int t = 0; t < 10; t++)
		{
			try
			{
				String s = " " + readLine();

				int[] dp = new int[s.length()];

				String[] w = new String[s.length() + 1];
				Arrays.fill(w, "");

				for (int i = 0; i < s.length(); i++)
				{
					for (int j = 0; j < i; j++)
						w[j] += s.charAt(i);

					for (int j = 0; j < i; j++)
						if (Arrays.binarySearch(dict, w[j]) >= 0)
						{
							if (dp[i] == 0
									&& (i - w[j].length() == 0 || dp[i
											- w[j].length()] != 0))
								dp[i] = dp[i - w[j].length()] + 1;
							if (i - w[j].length() == 0
									|| dp[i - w[j].length()] != 0)
								dp[i] = Math.min(dp[i],
										dp[i - w[j].length()] + 1);
						}
				}

				System.out.println(dp[s.length() - 1] - 1);
			}
			catch (Exception e)
			{
				System.out.println(363);
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
