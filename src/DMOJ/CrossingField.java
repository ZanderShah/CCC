package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CrossingField
{
	public static int[][] g;
	public static boolean p = false;
	public static int n, h;

	public static void solve(int x, int y, boolean[][] vis)
	{
		boolean[][] v = vis.clone();
		v[x][y] = true;

		if (x == n - 1 && y == n - 1)
		{
			System.out.println("yes");
			p = true;
		}

		if (!p)
		{
			if (x + 1 < n && Math.abs(g[x + 1][y] - g[x][y]) <= h
					&& !v[x + 1][y])
				solve(x + 1, y, v);
			if (y + 1 < n && Math.abs(g[x][y + 1] - g[x][y]) <= h
					&& !v[x][y + 1])
				solve(x, y + 1, v);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());

		g = new int[n][n];

		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++)
				g[i][j] = Integer.parseInt(st.nextToken());
		}

		solve(0, 0, new boolean[n][n]);
		
		if (!p)
			System.out.println("no");
	}

}
