package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SurpriseTeleport
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		int[][] g = new int[r][c];
		int[][] m = new int[r][c];

		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		m[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = 2;

		for (int i = 0; i < r; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < c; j++)
				if (s.charAt(j) == 'X')
					g[i][j]--;
		}

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++)
		{
			st = new StringTokenizer(br.readLine());
			m[Integer.parseInt(st.nextToken())][Integer
					.parseInt(st.nextToken())] = 1;
		}

		int norm = Integer.MAX_VALUE;
		int tele = Integer.MAX_VALUE;

		Queue<Integer[]> q = new LinkedList<Integer[]>();
		q.add(new Integer[] { x, y, 0 });
		g[x][y] = -1;

		while (!q.isEmpty())
		{
			Integer[] cur = q.poll();
			int a = cur[0];
			int b = cur[1];
			int d = cur[2];

			if (m[a][b] == 1 && d < tele)
				tele = d;

			if (m[a][b] == 2)
			{
				norm = d;
				break;
			}
			else
			{
				if (a - 1 >= 0 && g[a - 1][b] >= 0)
				{
					q.add(new Integer[] { a - 1, b, d + 1 });
					g[a - 1][b]--;
				}
				if (a + 1 < r && g[a + 1][b] >= 0)
				{
					q.add(new Integer[] { a + 1, b, d + 1 });
					g[a + 1][b]--;
				}
				if (b - 1 >= 0 && g[a][b - 1] >= 0)
				{
					q.add(new Integer[] { a, b - 1, d + 1 });
					g[a][b - 1]--;
				}
				if (b + 1 < c && g[a][b + 1] >= 0)
				{
					q.add(new Integer[] { a, b + 1, d + 1 });
					g[a][b + 1]--;
				}
			}
		}

		if (tele != Integer.MAX_VALUE && norm != Integer.MAX_VALUE)
			System.out.println(norm - tele);
		else if (norm != Integer.MAX_VALUE)
			System.out.println(norm);
		else
			System.out.println(0);
	}

}
