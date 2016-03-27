package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class dream
{
	public static int min = Integer.MAX_VALUE;
	public static int[][] g;
	public static int n, m;

	public static void solve(int x, int y, int d, boolean[][] vis, boolean smell)
	{
		if (x == n - 1 && y == m - 1)
			if (d < min)
				min = d;

		if (d >= 500)
			return;

		if (d < min && !vis[x][y])
		{
			boolean[][] v = vis.clone();

			v[x][y] = true;

			if (g[x][y] == 2)
				smell = true;

			if (g[x][y] == 4)
				smell = false;

			if (x + 1 < n && !v[x + 1][y] && g[x + 1][y] != 0
					&& (smell || g[x + 1][y] != 3))
			{
				if (g[x + 1][y] == 4)
				{
					int c = x;
					while (c + 1 < n && g[c + 1][y] == 4 && g[c + 1][y] != 0
							&& g[c + 1][y] != 3)
					{
						c++;
						d++;
					}
					if (!v[c][y])
					{
						smell = false;
						solve(c + 1, y, d + 1, v, smell);
					}
				}
				else
					solve(x + 1, y, d + 1, v, smell);
			}

			if (y + 1 < m && !v[x][y + 1] && g[x][y + 1] != 0
					&& (smell || g[x][y + 1] != 3))
			{
				if (g[x][y + 1] == 4)
				{
					int c = y;
					while (c + 1 < m && g[x][c + 1] == 4 && g[x][c + 1] != 0
							&& g[x][c + 1] != 3)
					{
						c++;
						d++;
					}

					if (!v[x][c])
					{
						smell = false;
						solve(x, c + 1, d + 1, v, smell);
					}
				}
				else
					solve(x, y + 1, d + 1, v, smell);
			}

			if (x - 1 >= 0 && !v[x - 1][y] && g[x - 1][y] != 0
					&& (smell || g[x - 1][y] != 3))
			{
				if (g[x - 1][y] == 4)
				{
					int c = x;
					while (c - 1 >= 0 && g[c - 1][y] == 4 && g[c - 1][y] != 0
							&& g[c - 1][y] != 3)
					{
						c--;
						d++;
					}
					if (!v[c][y])
					{
						smell = false;
						solve(c - 1, y, d + 1, v, smell);
					}
				}
				else
					solve(x - 1, y, d + 1, v, smell);
			}

			if (y - 1 >= 0 && !v[x][y - 1] && g[x][y - 1] != 0
					&& g[x][y - 1] != 3)
			{
				if (g[x][y - 1] == 4)
				{
					int c = y;
					while (c - 1 >= 0 && g[x][c - 1] == 4 && g[x][c - 1] != 0
							&& (smell || g[x][c - 1] != 3))
					{
						c--;
						d++;
					}

					if (!v[x][c])
					{
						smell = false;
						solve(x, c - 1, d + 1, v, smell);
					}
				}
				else
					solve(x, y - 1, d + 1, v, smell);
			}
		}
	}

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("dream.in"));
		PrintWriter out = new PrintWriter(new FileWriter("dream.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		g = new int[n][m];

		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++)
				g[i][j] = Integer.parseInt(st.nextToken());
		}

		solve(0, 0, 0, new boolean[n][m], false);

		if (min == Integer.MAX_VALUE)
			out.println(-1);
		else
			out.println(min);

		out.close();
	}

}
