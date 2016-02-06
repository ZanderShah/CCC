import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

/*
 * This one is not mine, it is Jacob Jackson's solution.
 */
public class LazyFox
{
	public static void main(String[] args) throws Exception
	{
		final Comparator<Integer[]> distance = new Comparator<Integer[]>() {
			public int compare(Integer[] a, Integer[] b)
			{
				return a[0] - b[0];
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int[][] c = new int[n + 1][2];

		for (int i = 1; i <= n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			c[i][0] = Integer.parseInt(st.nextToken());
			c[i][1] = Integer.parseInt(st.nextToken());
		}

		ArrayList<Integer[]> pairs = new ArrayList<Integer[]>();
		for (int i = 0; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				pairs.add(new Integer[] {
						(c[i][0] - c[j][0]) * (c[i][0] - c[j][0])
								+ (c[i][1] - c[j][1]) * (c[i][1] - c[j][1]), i,
						j });

		Collections.sort(pairs, distance);

		int[] best = new int[n + 1];
		int[] pbest = new int[n + 1];
		int[] pdist = new int[n + 1];

		for (Integer[] p : pairs)
		{
			int d = p[0];
			int a = p[1];
			int b = p[2];

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
