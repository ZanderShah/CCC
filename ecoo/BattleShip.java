package ecoo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BattleShip
{
	static int n, l;
	static char[][] g;
	static int ans = 0;

	static boolean checkVert(int i, int j)
	{
		if (i + l > n)
			return false;

		if (i - 1 >= 0)
		{
			if (g[i - 1][j] == 'h')
				return false;
			if (j - 1 >= 0 && g[i - 1][j - 1] == 'h')
				return false;
			if (j + 1 < n && g[i - 1][j + 1] == 'h')
				return false;
		}

		if (i + l < n)
		{
			if (g[i + l][j] == 'h')
				return false;
			if (j - 1 >= 0 && g[i + l][j - 1] == 'h')
				return false;
			if (j + 1 < n && g[i + l][j + 1] == 'h')
				return false;
		}

		for (int x = 0; x < l; x++)
		{
			if (g[i + x][j] == 'm')
				return false;
			if (j - 1 >= 0 && g[i + x][j - 1] == 'h')
				return false;
			if (j + 1 < n && g[i + x][j + 1] == 'h')
				return false;
		}

		return true;
	}

	static boolean checkHor(int i, int j)
	{
		if (j + l > n)
			return false;

		if (j - 1 >= 0)
		{
			if (g[i][j - 1] == 'h')
				return false;
			if (i - 1 >= 0 && g[i - 1][j - 1] == 'h')
				return false;
			if (i + 1 < n && g[i + 1][j - 1] == 'h')
				return false;
		}

		if (j + l < n)
		{
			if (g[i][j + l] == 'h')
				return false;
			if (i - 1 >= 0 && g[i - 1][j + l] == 'h')
				return false;
			if (i + 1 < n && g[i + 1][j + l] == 'h')
				return false;
		}

		for (int x = 0; x < l; x++)
		{
			if (g[i][j + x] == 'm')
				return false;
			if (i - 1 >= 0 && g[i - 1][j + x] == 'h')
				return false;
			if (i + 1 < n && g[i + 1][j + x] == 'h')
				return false;
		}

		return true;
	}

	public static void main(String[] args) throws Exception
	{
		for (int r = 0; r < 10; r++)
		{
			ans = 0;
			n = readInt();
			l = readInt();
			g = new char[n][n];
			for (int i = 0; i < n; i++)
			{
				String s = readLine();
				for (int j = 0; j < n; j++)
					g[i][j] = s.charAt(j);
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					if (checkVert(i, j))
						ans++;
					if (checkHor(i, j))
						ans++;
				}

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
