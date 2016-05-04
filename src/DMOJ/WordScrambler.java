package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class WordScrambler
{
	static void go(String w)
	{
		if (w.length() == c.length)
			System.out.println(w);
		for (int i = 0; i < used.length; i++)
			if (!used[i])
			{
				used[i] = true;
				go(w + c[i]);
				used[i] = false;
			}
	}
	
	static char[] c;
	static boolean[] used;
	public static void main(String[] args) throws Exception
	{
		c = readLine().toCharArray();
		Arrays.sort(c);
		used = new boolean[c.length];
		go("");
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
