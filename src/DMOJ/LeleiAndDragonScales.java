package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LeleiAndDragonScales
{
	public static int[][] grid;
	public static int n;

	public static int rectangles(int h, int w)
	{
		int max = 0;

		for (int r = 1; r <= Math.sqrt(n); r++)
		{
			int c = Math.min(h + r, grid.length) - 1;
			int d = Math.min(w + n / r, grid[0].length) - 1;

			int temp = 0;

			temp = grid[c][d] - grid[h - 1][d] - grid[c][w - 1] + grid[h - 1][w - 1];

			if (temp > max)
				max = temp;

			c = Math.min(h + n / r, grid.length) - 1;
			d = Math.min(w + r, grid[0].length) - 1;

			temp = 0;

			temp = grid[c][d] - grid[h - 1][d] - grid[c][w - 1] + grid[h - 1][w - 1];

			if (temp > max)
				max = temp;

		}

		return max;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int w = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());

		grid = new int[h + 1][w + 1];

		for (int i = 1; i <= h; i++)
		{
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= w; j++)
				grid[i][j] = Integer.parseInt(st.nextToken())
						+ grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
		}

		int max = 0;
		for (int i = 1; i <= h; i++)
			for (int j = 1; j <= w; j++)
			{
				int temp = rectangles(i, j);

				if (temp > max)
					max = temp;
			}

		System.out.println(max);
	}
}
