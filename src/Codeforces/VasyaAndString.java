package Codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class VasyaAndString
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), k = readInt();
		String s = readLine();
		int r = 0, cur = 0, max = 0;

		for (int i = 0; i < n; i++, r = Math.max(i, r))
		{
			while (r < n && (s.charAt(r) == 'a' || cur < k))
			{
				if (s.charAt(r) != 'a')
					cur++;
				r++;
			}

			if (cur > 0 && s.charAt(i) != 'a')
				cur--;
			max = Math.max(max, r - i);
		}

		r = 0;
		cur = 0;
		for (int i = 0; i < n; i++, r = Math.max(i, r))
		{
			while (r < n && (s.charAt(r) == 'b' || cur < k))
			{
				if (s.charAt(r) != 'b')
					cur++;
				r++;
			}

			if (cur > 0 && s.charAt(i) != 'b')
				cur--;
			max = Math.max(max, r - i);
		}

		System.out.println(max);
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
