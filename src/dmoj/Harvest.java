package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Harvest
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int m = readInt();
		long k = readLong();

		if (k == 0)
			System.out.println(0);
		else
		{
			long[] farm = new long[n + 1];

			for (int i = 0, a, b; i < m; i++)
			{
				a = readInt() - 1;
				b = readInt();
				farm[a]--;
				farm[b]++;
			}

			for (int i = 1; i < n; i++)
				farm[i] += farm[i - 1];
			farm[0] += m;
			for (int i = 1; i < n; i++)
				farm[i] += m + farm[i - 1];

			int best = n + 1;
			int upper = n;
			int lower = 0;

			for (int j = n / 2, w = 0, r = 0; r < 19; r++)
			{
				for (int i = 0; i + j < n; i++)
					if (i == 0)
					{
						if (farm[j + i] >= k)
							w = j + 1;
					}
					else if (farm[j + i] - farm[i - 1] >= k)
						w = j + 1;

				if (w != 0)
				{
					upper = (upper + lower) / 2;
					j = (lower + upper) / 2;
					best = Math.min(best, w);
					w = 0;
				}
				else
				{
					lower = (upper + lower) / 2;
					j = (lower + upper) / 2;
				}
			}

			if (best == n + 1)
				System.out.println(-1);
			else
				System.out.println(best);
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
