package vmss;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class HelloOfficer
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken()) - 1;
		int q = Integer.parseInt(st.nextToken());
		
		int[][] g = new int[n][n];

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()) - 1;
			int y = Integer.parseInt(st.nextToken()) - 1;
			int z = Integer.parseInt(st.nextToken());
			
			if (g[x][y] == 0)
			{
				g[x][y] = z;
				g[y][x] = z;
			}
			else
			{
				g[x][y] = Math.min(g[x][y], z);
				g[y][x] = g[x][y];
			}
		}
		
		int[] d = new int[n];
		for (int i = 0; i < n; i++)
			d[i] = -1;
		d[b] = 0;
		boolean[] v = new boolean[n];
		
		while (true)
		{
			int u = -1;
			int best = Integer.MAX_VALUE;
			
			for (int i = 0; i < n; i++)
				if (!v[i] && d[i] != -1 && best > d[i])
				{
					u = i;
					best = d[i];
				}

			if (best == Integer.MAX_VALUE)
				break;
			
			for (int i = 0; i < n; i++)
				if (!v[i] && g[u][i] > 0)
					if (d[i] == -1 || d[i] > d[u] + g[u][i])
						d[i] = d[u] + g[u][i];
					
			v[u] = true;
		}
		
		for (int i = 0; i < q; i++)
			System.out.println(d[Integer.parseInt(br.readLine()) - 1]);
	}

}
