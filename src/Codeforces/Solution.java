package Codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Solution
{

	public static void main(String[] args) throws Exception
	{
		int t = readInt();
		for (int q = 0; q < t; q++)
		{
			int m = readInt();
			int n = readInt();

			int[] c = new int[n];
			int[] x = new int[n];
			for (int i = 0; i < n; i++)
			{
				x[i] = readInt();
				c[i] = x[i];
			}

			Arrays.sort(x);
			int b = n - 1;
			int a = 0;
			for (; a < b; a++)
			{
				while (b > a && x[a] + x[b] > m)
					b--;
				if (x[a] + x[b] == m)
					break;
			}

			int j = 0;
			int low = -1;
			int up = -1;
			
			for (; j < n && low == -1; j++)
				if (c[j] == x[a] || c[j] == x[b])
					low = j + 1;
			for (; j < n && up == -1; j++)
				if (c[j] == x[a] || c[j] == x[b])
					up = j + 1;

			System.out.println(low + " " + up);
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