package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Snowman
{
	public static int[] b;
	public static int m, n;
	public static boolean done = false;
	
	public static void snow(int q, char[][] grid)
	{
		if (!done)
			if (q == -1)
			{
				System.out.println("yes");
				done = true;
			}
			else
			{
				int l = b[q];

				for (int i = 0; i < m; i++)
					for (int j = 0; j < n - l + 1; j++)
						for (int s = 0; s < l; s++)
						{
							if (grid[i][j + s] == '1')
								break;

							if (s == l - 1)
							{
								char[][] g = grid.clone();
								for (int t = 0; t < l; t++)
									g[i][j + t] = '1';
								snow(q - 1, g);
							}
						}

				for (int i = 0; i < n; i++)
					for (int j = 0; j < m - l + 1; j++)
						for (int s = 0; s < l; s++)
						{
							if (grid[j + s][i] == '1')
								break;

							if (s == l - 1)
							{
								char[][] g = grid.clone();
								for (int t = 0; t < l; t++)
									g[j + 1][i] = '1';
								snow(q - 1, g);
							}
						}
			}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());
		b = new int[s];

		for (int i = 0; i < s; i++)
			b[i] = Integer.parseInt(br.readLine());

		Arrays.sort(b);

		char[][] g = new char[m][n];
		for (int i = 0; i < m; i++)
		{
			String r = br.readLine();
			for (int j = 0; j < n; j++)
				g[i][j] = r.charAt(j);
		}

		snow(s - 1, g);
		
		if (!done)
			System.out.println("no");
	}

}
