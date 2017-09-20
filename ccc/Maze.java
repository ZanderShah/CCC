package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Maze
{
	public static int r, c;
	public static char[][] maze;
	public static int[][] memo;

	public static void solve(int x, int y, int m, boolean[][] vis)
	{
		boolean[][] go = new boolean[r][c];
		vis[x][y] = true;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				go[i][j] = vis[i][j];

		if (m < memo[x][y] && maze[x][y] != '*')
		{
			memo[x][y] = m;
			
			if (x == r - 1 && y == c - 1 && memo[x][y] == r + c + 1)
				return;
			else
			{
				if (maze[x][y] == '|' || maze[x][y] == '+')
				{
					if (x + 1 < r && !go[x + 1][y])
						solve(x + 1, y, m + 1, go);
					if (x - 1 >= 0 && !go[x - 1][y])
						solve(x - 1, y, m + 1, go);
				}
				if (maze[x][y] == '-' || maze[x][y] == '+')
				{
					if (y + 1 < c && !go[x][y + 1])
						solve(x, y + 1, m + 1, go);
					if (y - 1 >= 0 && !go[x][y - 1])
						solve(x, y - 1, m + 1, go);
				}
			}
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		for (int cases = 0; cases < t; cases++)
		{
			r = Integer.parseInt(br.readLine());
			c = Integer.parseInt(br.readLine());

			maze = new char[r][c];
			boolean[][] vis = new boolean[r][c];
			memo = new int[r][c];
			
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					memo[i][j] = Integer.MAX_VALUE;

			for (int i = 0; i < r; i++)
			{
				String s = br.readLine();
				for (int j = 0; j < c; j++)
					maze[i][j] = s.charAt(j);
			}

			solve(0, 0, 1, vis);

			if (memo[r - 1][c - 1] == Integer.MAX_VALUE)
				System.out.println(-1);
			else
				System.out.println(memo[r - 1][c - 1]);
		}
	}

}
