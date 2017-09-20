package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class QualifyingContest
{
	static class Person implements Comparable<Person>
	{
		int x;
		String n;

		Person(String nn, int xx)
		{
			n = nn;
			x = xx;
		}

		public int compareTo(Person p)
		{
			return p.x - x;
		}
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = readInt();
		ArrayList<Person>[] r = new ArrayList[m];
		for (int i = 0; i < m; i++)
			r[i] = new ArrayList<Person>();

		for (int i = 0; i < n; i++)
		{
			String s = next();
			int t = readInt() - 1, x = readInt();
			r[t].add(new Person(s, x));
		}

		for (int i = 0; i < m; i++)
		{
			Collections.sort(r[i]);

			if (r[i].size() < 2
					|| (r[i].size() > 2 && r[i].get(1).x == r[i].get(2).x))
				System.out.println("?");
			else
				System.out.println(r[i].get(0).n + " " + r[i].get(1).n);
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
