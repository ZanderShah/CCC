package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class lightson
{
	public static boolean[][] g;
	public static boolean[][] r;
	public static int n;

	public static boolean reach(int x, int y)
	{
		if (g[x][y]
				&& ((x - 1 >= 0 && r[x - 1][y]) || (y - 1 >= 0 && r[x][y - 1])
						|| (x + 1 < n && r[x + 1][y]) || (y + 1 < n && r[x][y + 1])))
			return true;

		return false;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("lightson.in"));
		PrintWriter out = new PrintWriter(new FileWriter("lightson.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int l = 1;

		g = new boolean[n][n];
		r = new boolean[n][n];
		g[0][0] = true;
		r[0][0] = true;

		Queue<Integer[]> q = new LinkedList<Integer[]>();

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());

			int x = Integer.parseInt(st.nextToken()) - 1;
			int y = Integer.parseInt(st.nextToken()) - 1;
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;

			if (!r[x][y] && reach(x, y))
				r[x][y] = true;

			if (r[x][y])
			{
				if (!g[a][b])
					l++;

				g[a][b] = true;

				if (!r[a][b] && reach(a, b))
					r[a][b] = true;
			}
			else
				q.add(new Integer[] { x, y, a, b });
		}

		int c = 0;

		while (c != q.size())
		{
			for (int k = 0; k < n; k++)
				for (int j = 0; j < n; j++)
					if (!r[k][j] && reach(k, j))
						r[k][j] = true;

			c = q.size();
			for (int i = 0; i < c; i++)
			{
				Integer[] s = q.poll();

				int x = s[0];
				int y = s[1];
				int a = s[2];
				int b = s[3];

				if (!r[x][y] && reach(x, y))
					r[x][y] = true;

				if (r[x][y])
				{
					if (!g[a][b])
						l++;

					g[a][b] = true;

					if (!r[a][b] && reach(a, b))
						r[a][b] = true;
				}
				else
					q.add(new Integer[] { x, y, a, b });
			}
		}

		out.println(l);
		out.close();
	}
}
