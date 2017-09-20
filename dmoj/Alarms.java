package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Alarms
{
	public static int n, a, max = 0;
	public static int[] r;
	public static int[][] g;

	public static int check()
	{
		ArrayList<Integer[]> alarms = new ArrayList<Integer[]>();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] > 1)
					alarms.add(new Integer[] { i, j, r[g[i][j] - 2] });

		int[][] temp = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				temp[i][j] = g[i][j];

		for (Integer[] c : alarms)
		{
			int x = c[0];
			int y = c[1];
			int range = c[2] - 1;

			for (int i = x - range; i <= x + range; i++)
				for (int j = y - range; j <= y + range; j++)
					if (temp[i][j] > 0)
						temp[i][j] = 2;
		}

		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (temp[i][j] > 1)
					count++;
		return count;
	}

	public static void secure(int i)
	{
		if (i == a)
			max = Math.max(max, check());
		else
		{
			for (int x = r[i] - 1; x < n - (r[i] - 1); x++)
				for (int y = r[i] - 1; y < n - (r[i] - 1); y++)
					if (g[x][y] == 1 && fine(g, x, y))
					{
						g[x][y] = i + 2;
						secure(i + 1);
						g[x][y] = 1;
					}

			secure(i + 1);
		}
	}

	public static boolean fine(int[][] g, int x, int y)
	{
		for (int i = 0; i < n; i++)
			if (g[i][y] > 1 || g[x][i] > 1)
				return false;
		return true;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		g = new int[n][n];
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++)
				g[i][j] = Integer.parseInt(st.nextToken());
		}

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		a = Integer.parseInt(st.nextToken());
		r = new int[a];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < a; i++)
			r[i] = Integer.parseInt(st.nextToken());

		secure(0);

		System.out.println(max);
	}

}
