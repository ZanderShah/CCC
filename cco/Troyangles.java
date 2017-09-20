package cco;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Troyangles
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[][] g = new int[n][n];

		int t = 0;
		for (int i = 0; i < n; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < n; j++)
				if (s.charAt(j) == '#')
				{
					g[i][j] = 1;
					t++;
				}
		}

		// Goes through the array one row at a tame
		// When you can make a triangle, keep track of that by letting the bottom right
		// corner of the triangle represent the maximum triangle you can make
		// You can therefore make a larger triangle when your streak is 2 greater
		// than the streak found above
		for (int i = 1; i < n; i++)
		{
			int streak = 0;
			for (int j = 0; j < n; j++)
			{
				if (g[i][j] > 0)
					streak++;
				else
					streak = 0;

				if (j > 0 && g[i - 1][j - 1] > 0)
				{
					int l = Math.min(g[i - 1][j - 1], (streak - 1) / 2);
					g[i][j] += l;
					t += l;
				}
			}
		}

		System.out.println(t);
	}

}
