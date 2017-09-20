package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class ColdWarTelecom
{
	static int n, cur = 0;
	static ArrayList<Integer>[] g;
	static int[] dfsNum, colour;
	static boolean[] crucial;
	static ArrayList<Integer> ans = new ArrayList<Integer>();

	static int dfs(int u, int p)
	{
		colour[u] = 1;
		dfsNum[u] = cur++;
		int leastAncestor = cur;

		for (int v : g[u])
			if (v != p)
				if (colour[v] == 0)
				{
					int rec = dfs(v, u);
					if (rec > dfsNum[u] && !crucial[u])
					{
						crucial[u] = true;
						ans.add(u + 1);
					}
					if (leastAncestor > rec)
						leastAncestor = rec;
				}
				else if (leastAncestor > dfsNum[v])
					leastAncestor = dfsNum[v];

		colour[u] = 2;
		return leastAncestor;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();

		for (int i = 0, x, y; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken()) - 1;
			y = Integer.parseInt(st.nextToken()) - 1;

			g[x].add(y);
			g[y].add(x);
		}

		dfsNum = new int[n];
		colour = new int[n];
		crucial = new boolean[n];
		dfs(0, -1);

		System.out.println(ans.size());
		Collections.sort(ans);
		for (int i : ans)
			out.println(i);
		out.close();
	}

}