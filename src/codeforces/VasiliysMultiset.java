package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class VasiliysMultiset
{
	static class Node
	{
		int c;
		Node l, r;

		Node()
		{
			c = 0;
			l = r = null;
		}
	}

	static void insert(Node n, int x, int d, int lvl)
	{
		if (lvl < 0)
			return;

		int a = (x >> lvl) & 1;

		if (a == 0)
		{
			if (n.l == null)
				n.l = new Node();
			n.l.c += d;
			insert(n.l, x, d, lvl - 1);
		}
		else
		{
			if (n.r == null)
				n.r = new Node();
			n.r.c += d;
			insert(n.r, x, d, lvl - 1);
		}
	}

	static int query(Node n, int x, int lvl)
	{
		if (lvl < 0)
			return 0;

		int a = (x >> lvl) & 1;

		if (a == 1)
		{
			if (n.l != null && n.l.c > 0)
				return query(n.l, x, lvl - 1) + (1 << lvl);
			else if (n.r != null && n.r.c > 0)
				return query(n.r, x, lvl - 1);
		}
		else
		{
			if (n.r != null && n.r.c > 0)
				return query(n.r, x, lvl - 1) + (1 << lvl);
			else if (n.l != null && n.l.c > 0)
				return query(n.l, x, lvl - 1);
		}

		return 0;
	}

	public static void main(String[] args) throws Exception
	{
		int q = readInt();

		Node root = new Node();
		insert(root, 0, 1, 30);

		for (int i = 0; i < q; i++)
		{
			char c = readChar();
			int x = readInt();

			if (c == '+')
				insert(root, x, 1, 30);
			else if (c == '-')
				insert(root, x, -1, 30);
			else
				out.println(query(root, x, 30));
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
