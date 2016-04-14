package TODO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SoSo
{
	// Incomplete
	static int r, c, g[][];

	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 10; t++)
		{
			r = readInt();
			c = readInt();

			for (int q = 0; q < 5; q++)
			{
				g = new int[r][c];
				int xC = 0;
				int oC = 0;
				for (int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						if (readChar() == 'X')
						{
							g[i][j] = 1;
							xC++;
						}
						else
						{
							g[i][j] = 2;
							oC++;
						}

				if (xC < 3 || oC < 3)
					System.out.print("N");
				else
				{
					
				}
			}
			System.out.println();
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
