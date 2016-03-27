package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class LazyFox
{
	public static class Path implements Comparable<Path>
	{
		int a, b, d;

		public Path(int a, int b, int d)
		{
			this.a = a;
			this.b = b;
			this.d = d;
		}

		public int compareTo(Path x)
		{
			return d - x.d;
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[][] c = new int[n + 1][2];

		for (int i = 1; i <= n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			c[i][0] = Integer.parseInt(st.nextToken());
			c[i][1] = Integer.parseInt(st.nextToken());
		}

		ArrayList<Path> all = new ArrayList<Path>();

		for (int i = 0; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				all.add(new Path(i, j, (c[i][0] - c[j][0])
						* (c[i][0] - c[j][0])
						+ (c[i][1] - c[j][1]) * (c[i][1] - c[j][1])));

		Collections.sort(all);

		int[] best = new int[n + 1];
		int[] pbest = new int[n + 1];
		int[] pdist = new int[n + 1];

		for (Path p : all)
		{
			int d = p.d;
			int a = p.a;
			int b = p.b;

			if (d != pdist[a])
			{
				pdist[a] = d;
				pbest[a] = best[a];
			}
			if (d != pdist[b])
			{
				pdist[b] = d;
				pbest[b] = best[b];
			}

			if (a == 0)
				best[a] = Math.max(best[a], pbest[b]);
			else
			{
				best[a] = Math.max(best[a], pbest[b] + 1);
				best[b] = Math.max(best[b], pbest[a] + 1);
			}
		}

		System.out.println(best[0] + 1);
	}
}
