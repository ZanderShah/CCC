package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class FloorPlan
{
	public static int[][] g;

	/**
	 * Tags an empty room with a specific number
	 * 
	 * @param x the current x-position
	 * @param y the current y-position
	 * @param t the number to tag
	 */
	public static void tag(int x, int y, int t)
	{
		g[x][y] = t;
		if (x + 1 < g.length && g[x + 1][y] == 0)
			tag(x + 1, y, t);
		if (x - 1 >= 0 && g[x - 1][y] == 0)
			tag(x - 1, y, t);
		if (y + 1 < g[0].length && g[x][y + 1] == 0)
			tag(x, y + 1, t);
		if (y - 1 >= 0 && g[x][y - 1] == 0)
			tag(x, y - 1, t);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int f = Integer.parseInt(br.readLine());
		int r = Integer.parseInt(br.readLine());
		int c = Integer.parseInt(br.readLine());

		g = new int[r][c];

		for (int i = 0; i < r; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < c; j++)
				if (s.charAt(j) == 'I')
					g[i][j] = -1;
		}

		// Goes through the array and tags each unique room
		int t = 1;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (g[i][j] == 0)
				{
					tag(i, j, t);
					t++;
				}

		int[] a = new int[t];

		// Counts the area of each room
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (g[i][j] > 0)
					a[g[i][j]]++;

		Arrays.sort(a);
		String s = null;

		for (int i = 0; i <= t - 1; i++)
		{
			if (f >= a[t - 1 - i])
				f -= a[t - 1 - i];
			else
			{
				if (i != 1)
					s = i + " rooms, " + f + " square metre(s) left over";
				else
					s = i + " room, " + f + " square metre(s) left over";
				break;
			}
		}
		if (s == null)
			if (t - 1 != 1)
				System.out.println(t - 1 + " rooms, " + f
						+ " square metre(s) left over");
			else
				System.out.println(t - 1 + " room, " + f
						+ " square metre(s) left over");
		else
			System.out.println(s);
	}
}
