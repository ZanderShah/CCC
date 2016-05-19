package TODO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Piramida
{

	public static void main(String[] args) throws Exception
	{
		readLong();
		String s = readLine();
		int[][] l = new int[s.length() + 1][26];

		for (int i = 0; i < s.length(); i++)
		{
			l[i + 1][s.charAt(i) - 'A']++;
			for (int j = 0; j < 26; j++)
				l[i + 1][j] += l[i][j];
		}

		int k = readInt();

		for (int i = 0; i < k; i++)
		{
			long x = readLong();
			int c = readChar() - 'A';

			long a = x * (x - 1) / 2;
			long b = x * (x + 1) / 2 - 1;

			long ans = 0;

			if (a % s.length() != 0)
			{
				ans += l[s.length()][c] - l[(int) (a % s.length())][c];
				a += s.length() - a % s.length();
			}

			if (a > b)
				ans -= l[s.length()][c] - l[(int) (b % s.length())][c];
			else
				ans += (b - a) / s.length() * l[s.length()][c]
						+ l[(int) (b % s.length()) + 1][c]
						- l[(int) (a % s.length())][c];

			System.out.println(ans);
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
