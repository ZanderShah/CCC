package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Contagion
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		long[] x = new long[n];
		long[] y = new long[n];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());

			x[i] = Long.parseLong(st.nextToken());
			y[i] = Long.parseLong(st.nextToken());
		}

		long[][] dis = new long[n][n];

		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				dis[i][j] = (x[i] - x[j]) * (x[i] - x[j])
						+ (y[i] - y[j])
						* (y[i] - y[j]);
				dis[j][i] = dis[i][j];
			}

		long[] time = new long[n];
		boolean[] vis = new boolean[n];

		for (int i = 0; i < n; i++)
			time[i] = Long.MAX_VALUE;

		int d = Integer.parseInt(br.readLine()) - 1;
		time[d] = 0;

		while (true)
		{
			int u = -1;
			long bestDist = Long.MAX_VALUE;

			for (int i = 0; i < n; i++)
				if (!vis[i] && time[i] < bestDist)
				{
					u = i;
					bestDist = time[i];
				}

			if (bestDist == Long.MAX_VALUE)
				break;

			for (int v = 0; v < n; v++)
				if (!vis[v])
					time[v] = Math.min(time[v], time[u] + dis[u][v]);

			vis[u] = true;
		}

		Arrays.sort(time);

		long queries = Long.parseLong(br.readLine());

		for (long i = 0; i < queries; i++)
		{
			long qu = Long.parseLong(br.readLine());
			int t = Math.abs(Arrays.binarySearch(time, qu) + 1);
			
			if (t - 1 >= 0 && t < n && time[t - 1] == time[t])
			{
				t = Math.abs(Arrays.binarySearch(time, qu + 1) + 1);
			}

			System.out.println(t);
		}
	}

}
