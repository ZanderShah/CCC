package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class TanyaAndToys
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = readInt();

		HashSet<Integer> h = new HashSet<Integer>();
		for (int i = 0; i < n; i++)
			h.add(readInt());

		ArrayList<Integer> b = new ArrayList<Integer>();
		for (int i = 1; m >= i; i++)
			if (!h.contains(i))
			{
				b.add(i);
				m -= i;
			}

		System.out.println(b.size());
		for (int i : b)
			System.out.print(i + " ");
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
