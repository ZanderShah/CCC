package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class TheseusAndLabyrinth
{
	static class State
	{
		int x, y, l, d;

		State(int xx, int yy, int ll, int dd)
		{
			x = xx;
			y = yy;
			l = ll;
			d = dd;
		}
	}

	public static void main(String[] args) throws Exception
	{
		String up = "+|^LRD", down = "+|vLRU", left = "+-<RUD", right = "+->LUD";

		int n = readInt(), m = readInt(), min = -1;

		char[][][] g = new char[n][m][4];

		for (int i = 0; i < n; i++)
		{
			String s = readLine();
			for (int j = 0; j < m; j++)
			{
				g[i][j][0] = s.charAt(j);
				for (int z = 1; z < 4; z++)
				{
					char c = g[i][j][z - 1];
					if (c == '-')
						g[i][j][z] = '|';
					else if (c == '|')
						g[i][j][z] = '-';
					else if (c == '^')
						g[i][j][z] = '>';
					else if (c == '>')
						g[i][j][z] = 'v';
					else if (c == 'v')
						g[i][j][z] = '<';
					else if (c == '<')
						g[i][j][z] = '^';
					else if (c == 'L')
						g[i][j][z] = 'U';
					else if (c == 'U')
						g[i][j][z] = 'R';
					else if (c == 'R')
						g[i][j][z] = 'D';
					else if (c == 'D')
						g[i][j][z] = 'L';
					else if (c == '*')
						g[i][j][z] = '*';
					else if (c == '+')
						g[i][j][z] = '+';
				}
			}
		}

		boolean[][][] vis = new boolean[n][m][4];
		Queue<State> q = new LinkedList<State>();
		q.add(new State(readInt() - 1, readInt() - 1, 0, 0));
		int x = readInt() - 1, y = readInt() - 1;

		while (!q.isEmpty())
		{
			State p = q.poll();

			if (!vis[p.x][p.y][p.l])
			{
				vis[p.x][p.y][p.l] = true;

				if (p.x == x && p.y == y)
				{
					min = p.d;
					break;
				}

				if (!vis[p.x][p.y][(p.l + 1) % 4])
					q.add(new State(p.x, p.y, (p.l + 1) % 4, p.d + 1));

				if (p.x - 1 >= 0 && !vis[p.x - 1][p.y][p.l]
						&& up.indexOf(g[p.x][p.y][p.l]) != -1
						&& down.indexOf(g[p.x - 1][p.y][p.l]) != -1)
					q.add(new State(p.x - 1, p.y, p.l, p.d + 1));

				if (p.x + 1 < n && !vis[p.x + 1][p.y][p.l]
						&& down.indexOf(g[p.x][p.y][p.l]) != -1
						&& up.indexOf(g[p.x + 1][p.y][p.l]) != -1)
					q.add(new State(p.x + 1, p.y, p.l, p.d + 1));

				if (p.y - 1 >= 0 && !vis[p.x][p.y - 1][p.l]
						&& left.indexOf(g[p.x][p.y][p.l]) != -1
						&& right.indexOf(g[p.x][p.y - 1][p.l]) != -1)
					q.add(new State(p.x, p.y - 1, p.l, p.d + 1));

				if (p.y + 1 < m && !vis[p.x][p.y + 1][p.l]
						&& right.indexOf(g[p.x][p.y][p.l]) != -1
						&& left.indexOf(g[p.x][p.y + 1][p.l]) != -1)
					q.add(new State(p.x, p.y + 1, p.l, p.d + 1));
			}
		}

		System.out.println(min);
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
