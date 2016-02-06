import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DegreesOfSeparation
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		int t = Integer.parseInt(br.readLine());

		int[][] d = new int[n][n];

		int a, b, c, r = 0;

		while (r < t)
		{
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken()) - 1;
			b = Integer.parseInt(st.nextToken()) - 1;
			c = Integer.parseInt(st.nextToken());

			if (a != b && (d[Math.max(a, b)][Math.min(a, b)] == 0
					|| d[Math.max(a, b)][Math.min(a, b)] > c))
				d[Math.max(a, b)][Math.min(a, b)] = c;

			r++;
		}

		int k = Integer.parseInt(br.readLine());

		int[] p = new int[n];
		int[] cost = new int[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = -1;
			cost[i] = 1000000;
		}

		int realK = k, shop;
		r = 0;

		while (r < k)
		{
			st = new StringTokenizer(br.readLine());

			shop = Integer.parseInt(st.nextToken()) - 1;

			if (p[shop] != -1)
			{
				p[shop] = Math.min(p[shop], Integer.parseInt(st.nextToken()));
				realK--;
			}
			else
				p[shop] = Integer.parseInt(st.nextToken());

			r++;
		}

		cost[Integer.parseInt(br.readLine()) - 1] = 0;

		boolean[] vis = new boolean[n];

		int min = 1000000;
		int sure = 0;

		while (true)
		{
			if (sure == realK)
				break;

			int u = -1;
			int best = 1000000;

			for (int i = 0; i < n; i++)
				if (!vis[i] && cost[i] < best)
				{
					u = i;
					best = cost[i];
				}

			if (best > min)
				break;
			
			vis[u] = true;
			
			for (int i = 0; i < n; i++)
				if (!vis[i]
						&& d[Math.max(i, u)][Math.min(u, i)] > 0
						&& cost[i] > cost[u]
								+ d[Math.max(i, u)][Math.min(u, i)])
					cost[i] = cost[u] + d[Math.max(i, u)][Math.min(u, i)];

			
			if (p[u] >= 0)
			{
				sure++;
				min = Math.min(cost[u] + p[u], min);
			}
		}

		System.out.println(min);
	}
}
