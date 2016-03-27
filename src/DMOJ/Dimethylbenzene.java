package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Dimethylbenzene
{
	public static boolean loop = false;
	public static boolean[][] g;

	public static void solve(int e, int c, int l, boolean[] vis)
	{
		boolean[] v = vis.clone();

		if (e == c && l == 6)
		{
			loop = true;
		}
		else
		{
			v[c] = true;

			for (int i = 0; i < g.length; i++)
			{
				if (g[c][i] && (!v[i] || (i == e && l == 5)))
					solve(e, i, l + 1, v);
			}
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		if (n < 6)
			System.out.println("NO");
		else
		{
			g = new boolean[n][n];

			for (int i = 0; i < m; i++)
			{
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken()) - 1;
				int b = Integer.parseInt(st.nextToken()) - 1;

				g[a][b] = true;
				g[b][a] = true;
			}

			for (int i = 0; i < n; i++)
			{
				solve(i, i, 0, new boolean[n]);

				if (loop)
				{
					System.out.println("YES");
					break;
				}
			}

			if (!loop)
				System.out.println("NO");
		}
	}
}
