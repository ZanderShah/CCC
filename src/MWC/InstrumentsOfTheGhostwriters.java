package MWC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class InstrumentsOfTheGhostwriters
{
	public static void main(String[] args) throws Exception
	{
		int c = readInt();
		int r = readInt();
		int m = readInt();
		int q = readInt();
		int[] rowM = new int[r + 1], colM = new int[c + 1], rowD = new int[r + 1], colD = new int[c + 1], colZero = new int[c + 1], rowZero = new int[r + 1];
		long[][] sum = new long[r + 1][c + 1];

		for (int i = 0; i <= r; i++)
		{
			rowM[i] = 1;
			rowD[i] = 1;
		}
		for (int i = 0; i <= c; i++)
		{
			colM[i] = 1;
			colD[i] = 1;
		}

		for (int i = 0, x, y, f; i < m; i++)
		{
			char j = readChar();
			x = readInt() - 1;
			y = readInt();
			f = readInt();

			if (j == 'c')
			{
				if (f == 0)
				{
					colZero[x]++;
					colZero[y]--;
				}
				else
				{
					colM[x] *= f;
					colD[y] *= f;
				}
			}
			else
			{
				if (f == 0)
				{
					rowZero[x]++;
					rowZero[y]--;
				}
				else
				{
					rowM[x] *= f;
					rowD[y] *= f;
				}
			}
		}

		for (int i = 1; i <= r; i++)
		{
			rowM[i] *= rowM[i - 1];
			rowD[i] *= rowD[i - 1];
			rowZero[i] += rowZero[i - 1];
		}

		for (int i = 1; i <= c; i++)
		{
			colM[i] *= colM[i - 1];
			colD[i] *= colD[i - 1];
			colZero[i] += colZero[i - 1];
		}

		for (int i = 1, v; i <= r; i++)
			for (int j = 1; j <= c; j++)
			{
				if (rowZero[i - 1] != 0 || colZero[j - 1] != 0)
					v = 0;
				else
					v = rowM[i - 1] * colM[j - 1]
							/ (rowD[i - 1] * colD[j - 1]);
				sum[i][j] = v + sum[i - 1][j]
						+ sum[i][j - 1]
						- sum[i - 1][j - 1];
			}

		TreeMap<Long, Integer> look = new TreeMap<Long, Integer>();
		for (int a = 1; a <= r; a++)
			for (int b = 1; b <= c; b++)
				for (int e = a; e <= r; e++)
					for (int d = b; d <= c; d++)
					{
						Integer k = look.get(sum[e][d] + sum[a - 1][b - 1]
								- sum[e][b - 1]
								- sum[a - 1][d]);
						if (k != null)
							look.replace(sum[e][d] + sum[a - 1][b - 1]
									- sum[e][b - 1]
									- sum[a - 1][d],
									k + 1);
						else
							look.put(sum[e][d] + sum[a - 1][b - 1]
									- sum[e][b - 1]
									- sum[a - 1][d], 1);
					}

		for (int i = 0; i < q; i++)
		{
			long x = readLong();
			long o = readLong();

			if (x == 0 && o == 0)
				out.println(r * (r + 1) / 2 * c * (c + 1) / 2);
			else if (x == 0 || o % x != 0)
				out.println(0);
			else
			{
				Integer v = look.get(o / x);
				if (v == null)
					out.println(0);
				else
					out.println(v);
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
