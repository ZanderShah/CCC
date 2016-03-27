package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class DianaSocializes
{
	static int n, m;
	static int[][] g;

	static void tag(int i, int j, int t)
	{
		if (g[i][j] == 0)
		{
			g[i][j] = t;

			if (i - 1 >= 0)
				tag(i - 1, j, t);
			if (i + 1 < n)
				tag(i + 1, j, t);
			if (j - 1 >= 0)
				tag(i, j - 1, t);
			if (j + 1 < m)
				tag(i, j + 1, t);
		}
	}

	static ArrayList<Integer> connect(int i, int j)
	{
		int connections = 0;
		ArrayList<Integer> current = new ArrayList<Integer>();

		if (i > 1 && g[i - 1][j] != -1 && !current.contains(g[i - 1][j]))
		{
			connections++;
			current.add(g[i - 1][j]);
		}
		if (i < n - 2 && g[i + 1][j] != -1 && !current.contains(g[i + 1][j]))
		{
			connections++;
			current.add(g[i + 1][j]);
		}
		if (j < m - 2 && g[i][j + 1] != -1 && !current.contains(g[i][j + 1]))
		{
			connections++;
			current.add(g[i][j + 1]);
		}
		if (j > 1 && g[i][j - 1] != -1 && !current.contains(g[i][j - 1]))
		{
			connections++;
			current.add(g[i][j - 1]);
		}

		Collections.sort(current);

		ArrayList<Integer> result = new ArrayList<Integer>();
		result.add(connections);
		result.add(i);
		result.add(j);
		for (int x : current)
			result.add(x);
		return result;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		g = new int[n][m];

		for (int i = 0; i < n; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < m; j++)
				if (s.charAt(j) == 'X')
					g[i][j] = -1;
		}

		int t = 1;
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				if (g[i][j] == 0)
				{
					tag(i, j, t);
					t++;
				}

		ArrayList<Integer> best = new ArrayList<Integer>();
		best.add(0);
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < m - 1; j++)
				if (g[i][j] == -1)
				{
					ArrayList<Integer> check = connect(i, j);
					if (check.get(0) > best.get(0))
					{
						best.clear();
						for (int q : check)
							best.add(q);
					}
					check.clear();
				}

		if (best.get(0) == 1)
			System.out.println(-1);
		else
		{
			System.out.println(best.get(0));
			System.out.println(best.get(2) + " " + best.get(1));
			for (int i = 3; i < best.size(); i++)
				if (i + 1 == best.size())
					System.out.print(best.get(i));
				else
					System.out.print(best.get(i) + " ");
		}
	}

}
