import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ConvexHull
{
	static boolean[] vis;
	static int min = Integer.MAX_VALUE;
	static int end;
	static Island[] islands;

	private static class Island
	{
		ArrayList<Route> paths = new ArrayList<Route>();

		int[] best = new int[200];
	}

	private static class Route
	{
		int n;
		int d;
		int t;

		public Route(int n, int d, int t)
		{
			this.n = n;
			this.d = d;
			this.t = t;
		}
	}

	public static void sail(int cur, int hull, int dis)
	{
		if (hull <= 0 || dis >= min || islands[cur].best[hull - 1] <= dis)
			return;

		if (cur == end)
		{
			min = dis;
			return;
		}

		islands[cur].best[hull - 1] = dis;

		vis[cur] = true;

		for (int i = 0; i < islands[cur].paths.size(); i++)
		{
			Route next = islands[cur].paths.get(i);

			if (!vis[next.n])
				sail(next.n, hull - next.d, dis + next.t);
		}

		vis[cur] = false;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int k = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		islands = new Island[n];
		for (int i = 0; i < n; i++)
		{
			islands[i] = new Island();
			Arrays.fill(islands[i].best, Integer.MAX_VALUE);
		}

		vis = new boolean[n];

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());

			Integer a = Integer.parseInt(st.nextToken()) - 1;
			Integer b = Integer.parseInt(st.nextToken()) - 1;
			Integer t = Integer.parseInt(st.nextToken());
			Integer hull = Integer.parseInt(st.nextToken());

			if (hull < k)
			{
				islands[a].paths.add(new Route(b, hull, t));
				islands[b].paths.add(new Route(a, hull, t));
			}
		}

		st = new StringTokenizer(br.readLine());

		int start = Integer.parseInt(st.nextToken()) - 1;
		end = Integer.parseInt(st.nextToken()) - 1;

		sail(start, k, 0);

		if (min == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(min);
	}
}
