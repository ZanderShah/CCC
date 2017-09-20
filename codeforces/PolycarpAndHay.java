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

public class PolycarpAndHay
{
	static int n, m, g[][], f[][], res[][], size, tag;
	static long k;

	static class Point implements Comparable<Point>
	{
		int v, x, y;

		Point(int vv, int xx, int yy)
		{
			v = vv;
			x = xx;
			y = yy;
		}

		public int compareTo(Point p)
		{
			return p.v - v;
		}
	}

	static void fill(int i, int j)
	{
		size++;
		f[i][j] = tag;

		if (i - 1 >= 0 && f[i - 1][j] != tag && g[i - 1][j] >= tag)
			fill(i - 1, j);
		if (j - 1 >= 0 && f[i][j - 1] != tag && g[i][j - 1] >= tag)
			fill(i, j - 1);
		if (i + 1 < n && f[i + 1][j] != tag && g[i + 1][j] >= tag)
			fill(i + 1, j);
		if (j + 1 < m && f[i][j + 1] != tag && g[i][j + 1] >= tag)
			fill(i, j + 1);
	}

	static void prepare(int i, int j)
	{
		if (size == k / tag)
			return;

		size++;
		res[i][j] = tag;

		if (i - 1 >= 0 && f[i - 1][j] == tag && res[i - 1][j] != tag)
			prepare(i - 1, j);
		if (j - 1 >= 0 && f[i][j - 1] == tag && res[i][j - 1] != tag)
			prepare(i, j - 1);
		if (i + 1 < n && f[i + 1][j] == tag && res[i + 1][j] != tag)
			prepare(i + 1, j);
		if (j + 1 < m && f[i][j + 1] == tag && res[i][j + 1] != tag)
			prepare(i, j + 1);
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		m = readInt();
		k = readLong();
		g = new int[n][m];
		f = new int[n][m];

		ArrayList<Point> v = new ArrayList<Point>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				g[i][j] = readInt();
				v.add(new Point(g[i][j], i, j));
			}

		Collections.sort(v);
		boolean done = false;

		for (int i = 0; i < v.size() && !done; i++)
		{
			tag = v.get(i).v;
			if (k % v.get(i).v == 0 && f[v.get(i).x][v.get(i).y] != tag
					&& v.get(i).v >= k / (i + 1))
			{
				size = 0;
				fill(v.get(i).x, v.get(i).y);
				if (size >= k / tag)
				{
					done = true;
					out.println("YES");
					size = 0;
					res = new int[n][m];
					prepare(v.get(i).x, v.get(i).y);
					for (int a = 0; a < n; a++)
					{
						for (int b = 0; b < m; b++)
							out.print(res[a][b] + " ");
						out.println();
					}
				}
			}
		}

		if (!done)
			out.println("NO");

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