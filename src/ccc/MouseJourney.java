package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class MouseJourney
{
	public static int r, c;
	public static boolean[][] cat;
	public static int[][] ways;

	/**
	 * Count the number of ways that a mouse the bottom rigth of a maze
	 * 
	 * @param x the current x-position
	 * @param y the current y-position
	 * @return the number of ways that the mouse can get to the bottom 
	 * 		right of the maze
	 */
	public static int solve(int x, int y)
	{
		if (ways[x][y] == 0)
		{
			if (x == r - 1 && y == c - 1)
				ways[x][y] = 1;

			if (x + 1 < r && !cat[x + 1][y])
				ways[x][y] += solve(x + 1, y);

			if (y + 1 < c && !cat[x][y + 1])
				ways[x][y] += solve(x, y + 1);
		}
		return ways[x][y];
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		cat = new boolean[r][c];

		int k = Integer.parseInt(br.readLine());

		for (int i = 0; i < k; i++)
		{
			st = new StringTokenizer(br.readLine());
			cat[Integer.parseInt(st.nextToken()) - 1][Integer.parseInt(st
					.nextToken()) - 1] = true;
		}

		ways = new int[r][c];

		System.out.println(solve(0, 0));
	}

}
