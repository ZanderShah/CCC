package mwc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BadNews
{
	static int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 },
			{ -1, -1 }, { -1, 1 }, { 1, -1 } };
	static char[][] g;
	static int n;
	static boolean[][] vis;
	static String word;

	static boolean find(int i, int j, String s)
	{
		if (s.equals(word))
			return true;

		if (s.charAt(s.length() - 1) != word.charAt(s.length() - 1))
			return false;

		for (int x = 0; x < 8; x++)
			if (!invalid(i + dir[x][0], j + dir[x][1])
					&& !vis[i + dir[x][0]][j + dir[x][1]])
			{
				vis[i + dir[x][0]][j + dir[x][1]] = true;
				if (find(i + dir[x][0], j + dir[x][1], s
						+ g[i + dir[x][0]][j + dir[x][1]]))
					return true;
				vis[i + dir[x][0]][j + dir[x][1]] = false;
			}

		return false;
	}

	static boolean invalid(int i, int j)
	{
		return i < 0 || i >= n || j < 0 || j >= n;
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		int q = readInt();

		g = new char[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = readChar();

		for (int c = 0; c < q; c++)
		{
			word = readLine();
			vis = new boolean[n][n];

			boolean sol = false;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (g[i][j] == word.charAt(0))
					{
						vis[i][j] = true;
						if (find(i, j, g[i][j] + ""))
							sol = true;
						vis[i][j] = false;
					}

			if (sol)
				System.out.println("good puzzle!");
			else
				System.out.println("bad puzzle!");
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