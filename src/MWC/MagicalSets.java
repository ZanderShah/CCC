package MWC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MagicalSets
{

	public static void main(String[] args) throws Exception
	{
		try
		{
			int n = readInt(), q = readInt();

			int[][] s = new int[n][61];

			for (int i = 0, x; i < n; i++)
			{
				x = readInt();
				for (int j = 0; j < x; j++)
					s[i][readInt() + 30]++;
			}

			for (int i = 0, x; i < q; i++)
			{
				x = readInt();
				int[] res = new int[61];
				for (int j = 0, a; j < x; j++)
				{
					a = readInt() - 1;
					for (int k = 0; k < 61; k++)
						res[k] += s[a][k];
				}

				ArrayList<Integer> ans = new ArrayList<Integer>();
				for (int j = 0; j < 61; j++)
					if (res[j] % 2 != 0)
						ans.add(j - 30);

				System.out.print(ans.size());
				for (int j : ans)
					System.out.print(" " + j);
				System.out.println();
			}
		}
		catch (Exception e)
		{

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
