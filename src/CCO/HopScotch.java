package CCO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HopScotch
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int sqrt = (int) Math.ceil(Math.sqrt(n));
		int[] pow = new int[n];
		int[] jump = new int[n];
		int[] turns = new int[n];

		for (int i = 0; i < n; i++)
			pow[i] = readInt();

		for (int i = 1; i <= sqrt; i++)
			for (int j = Math.min(sqrt * i, n - 1); j >= sqrt * (i - 1); j--)
				if (j + pow[j] >= Math.min(sqrt * i, n))
				{
					jump[j] = Math.min(j + pow[j], n);
					turns[j] = 1;
				}
				else
				{
					jump[j] = jump[j + pow[j]];
					turns[j] = turns[j + pow[j]] + 1;
				}

		int q = readInt();
		for (int i = 0, c, x, v, ans; i < q; i++)
		{
			c = readInt();
			x = readInt();
			if (c == 1)
			{
				ans = 0;
				while (x != n)
				{
					ans += turns[x];
					x = jump[x];
				}
				out.println(ans);
			}
			else
			{
				v = readInt();
				pow[x] = v;
				int block = (int) Math.ceil(x * 1.0 / sqrt);
				for (int j = Math.min(sqrt * block, n - 1); j >= Math.max(sqrt
						* (block - 1), 0); j--)
					if (j + pow[j] >= Math.min(sqrt * block, n))
					{
						jump[j] = Math.min(j + pow[j], n);
						turns[j] = 1;
					}
					else
					{
						jump[j] = jump[j + pow[j]];
						turns[j] = turns[j + pow[j]] + 1;
					}
			}
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
