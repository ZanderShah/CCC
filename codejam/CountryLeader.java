package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CountryLeader
{
	public static void main(String[] args) throws Exception
	{
		int T = readInt();

		for (int r = 1; r <= T; r++)
		{
			int N = readInt(), best = -1;
			String name = "";

			for (int i = 0; i < N; i++)
			{
				int cur = 0;
				String s = readLine();
				boolean[] vis = new boolean[26];

				for (int j = 0; j < s.length(); j++)
					if (s.charAt(j) != ' ')
					{
						int x = s.charAt(j) - 'A';

						if (!vis[x])
							cur++;
						vis[x] = true;

						if (cur > best)
						{
							best = cur;
							name = s;
						}
						else if (cur == best && s.compareTo(name) < 0)
						{
							name = s;
						}
					}
			}
			out.printf("Case #%d: %s\n", r, name);
		}
		out.close();
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
