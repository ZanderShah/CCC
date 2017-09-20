package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Watchmeblink1
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int k = readInt();
		int j = readInt();
		long[][] sum = new long[3][n + 2];
		int[] works = new int[3];

		for (int r = 0, x, f, i, t; r < j; r++)
		{
			x = readInt();
			f = readInt();
			i = readInt();
			t = readInt() - 1;
			sum[t][x] += i;
			sum[t][f + 1] -= i;
		}

		for (int i = 0; i < 3; i++)
			for (int q = 1; q <= n; q++)
			{
				sum[i][q] += sum[i][q - 1];
				if (sum[i][q] < k)
					works[i]++;
			}

		System.out.println(works[0] + "\n" + works[1] + "\n" + works[2]);
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
