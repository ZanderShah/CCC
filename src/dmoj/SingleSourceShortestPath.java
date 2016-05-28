package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SingleSourceShortestPath
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] g = new int[n][n];

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;

			if (g[a][b] == 0)
				g[a][b] = Integer.parseInt(st.nextToken());
			else
				g[a][b] = Math.min(g[a][b], Integer.parseInt(st.nextToken()));

			g[b][a] = g[a][b];
		}

		int[] d = new int[n];
		for (int i = 1; i < n; i++)
			d[i] = -1;
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
		
		for (int i : d)
			System.out.println(i);
	}

}
