package MWC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ThiefInTheNight
{

	public static void main(String[] args) throws Exception
	{
		int f = readInt(), r = readInt();
		int[][] sum = new int[f + 1][r + 1];
		
		for (int i = 0; i < f; i++)
			for (int j = 1; j <= r; j++)
				sum[i][j] = readInt() + sum[i][j - 1];
		
		int q = readInt();
		for (int i = 0, a, b, c; i < q; i++)
		{
			a = readInt() - 1;
			b = readInt();
			c = readInt() - 1;
			
			System.out.println(sum[c][b] - sum[c][a]);
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
