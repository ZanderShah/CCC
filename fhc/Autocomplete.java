package fhc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Autocomplete
{
	static class Node
	{
		Node[] c;

		Node()
		{
			c = new Node[26];
		}
	}

	static int insert(Node n, int i)
	{
		if (i == s.length())
			return 0;

		if (n.c[s.charAt(i) - 'a'] == null)
		{
			n.c[s.charAt(i) - 'a'] = new Node();

			if (!once)
				once = true;
			else
				return insert(n.c[s.charAt(i) - 'a'], i + 1);
		}

		return 1 + insert(n.c[s.charAt(i) - 'a'], i + 1);
	}

	static Node h;
	static String s;
	static boolean once;

	public static void main(String[] args) throws Exception
	{
		int T = readInt();
		for (int r = 1; r <= T; r++)
		{
			int N = readInt(), c = 0;
			h = new Node();

			for (int i = 0; i < N; i++)
			{
				s = readLine();
				once = false;
				c += insert(h, 0);
			}

			out.printf("Case #%d: %d\n", r, c);
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
