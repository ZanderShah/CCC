package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class KnightHop
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x1 = Integer.parseInt(st.nextToken()) - 1;
		int y1 = Integer.parseInt(st.nextToken()) - 1;
		st = new StringTokenizer(br.readLine());
		int x2 = Integer.parseInt(st.nextToken()) - 1;
		int y2 = Integer.parseInt(st.nextToken()) - 1;

		int[][] g = new int[8][8];
		Queue<Integer[]> q = new LinkedList<Integer[]>();
		q.add(new Integer[] { x1, y1, 0 });

		// Bfs on the chess board, numbering tiles by the minimum number
		// of moves it requires to get to them
		while (!q.isEmpty())
		{
			Integer[] c = q.poll();
			int x = c[0];
			int y = c[1];
			int d = c[2];

			if (x != x1 || y != y1)
				g[x][y] = d;

			if (x + 2 < 8 && y + 1 < 8 && g[x + 2][y + 1] == 0)
				q.add(new Integer[] { x + 2, y + 1, d + 1 });
			if (x + 1 < 8 && y + 2 < 8 && g[x + 1][y + 2] == 0)
				q.add(new Integer[] { x + 1, y + 2, d + 1 });
			if (x - 1 >= 0 && y + 2 < 8 && g[x - 1][y + 2] == 0)
				q.add(new Integer[] { x - 1, y + 2, d + 1 });
			if (x - 2 >= 0 && y + 1 < 8 && g[x - 2][y + 1] == 0)
				q.add(new Integer[] { x - 2, y + 1, d + 1 });
			if (x + 2 < 8 && y - 1 >= 0 && g[x + 2][y - 1] == 0)
				q.add(new Integer[] { x + 2, y - 1, d + 1 });
			if (x + 1 < 8 && y - 2 >= 0 && g[x + 1][y - 2] == 0)
				q.add(new Integer[] { x + 1, y - 2, d + 1 });
			if (x - 1 >= 0 && y - 2 >= 0 && g[x - 1][y - 2] == 0)
				q.add(new Integer[] { x - 1, y - 2, d + 1 });
			if (x - 2 >= 0 && y - 1 >= 0 && g[x - 2][y - 1] == 0)
				q.add(new Integer[] { x - 2, y - 1, d + 1 });
		}

		System.out.println(g[x2][y2]);

	}

}
