package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ShahirGetThere
{
	static boolean c = false;
	static boolean[][] g;
	static boolean[] v;
	static int n, b;

	public static void dfs(int i)
	{
		v[i] = true;

		if (!c)
			if (i == b)
				c = true;
			else
			{
				for (int j = 0; j < n; j++)
					if (!v[j] && g[i][j])
						dfs(j);
			}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken()) - 1;
		b = Integer.parseInt(st.nextToken()) - 1;

		g = new boolean[n][n];
		v = new boolean[n];

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()) - 1;
			int y = Integer.parseInt(st.nextToken()) - 1;

			g[x][y] = true;
			g[y][x] = true;
		}

		dfs(a);

		if (c)
			System.out.println("GO SHAHIR!");
		else
			System.out.println("NO SHAHIR!");
	}

}
