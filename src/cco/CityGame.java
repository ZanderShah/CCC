package cco;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class CityGame
{
	public static void main(String[] args) throws Exception
	{
		int k = readInt();

		for (int t = 0; t < k; t++)
		{
			int n = readInt(), m = readInt();

			int[][] g = new int[n][m];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (readChar() == 'F')
						g[i][j] = 1 + (i != 0 ? g[i - 1][j] : 0);

			int max = 0;
			Stack<Integer> s = new Stack<Integer>();

			for (int x = 0; x < n; x++)
			{
				s.clear();
				int temp;
				int[] width = new int[g[x].length];

				for (int i = 0; i < g[x].length; i++)
				{
					while (!s.isEmpty())
						if (g[x][i] <= g[x][s.peek()])
							s.pop();
						else
							break;

					if (s.isEmpty())
						temp = -1;
					else
						temp = s.peek();

					width[i] = i - temp - 1;
					s.push(i);
				}

				s.clear();

				for (int i = g[x].length - 1; i >= 0; i--)
				{
					while (!s.isEmpty())
						if (g[x][i] <= g[x][s.peek()])
							s.pop();
						else
							break;

					if (s.empty())
						temp = g[x].length;
					else
						temp = s.peek();

					width[i] += temp - i - 1;
					s.push(i);

					max = Math.max(max, (width[i] + 1) * g[x][i]);
				}
			}

			System.out.println(max * 3);
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
