package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class PursuitOfKnowledge
{
	public static class Room
	{
		ArrayList<Integer> halls = new ArrayList<Integer>();
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());

		Room[] rooms = new Room[n];
		for (int i = 0; i < n; i++)
			rooms[i] = new Room();

		int m = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			rooms[Integer.parseInt(st.nextToken()) - 1].halls.add(Integer
					.parseInt(st.nextToken()) - 1);
		}

		int[][] dis = new int[n][n];

		for (int i = 0; i < n; i++)
		{
			Queue<Integer[]> q = new LinkedList<Integer[]>();
			q.add(new Integer[] { i, 0 });

			while (!q.isEmpty())
			{
				Integer[] c = q.poll();

				if (c[0] != i && dis[i][c[0]] == 0)
					dis[i][c[0]] = c[1];

				for (Integer r : rooms[c[0]].halls)
					if (dis[i][r] == 0)
						q.add(new Integer[] { r, c[1] + 1 });
			}
		}

		int q = Integer.parseInt(br.readLine());

		for (int i = 0; i < q; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;

			if (dis[a][b] == 0)
				System.out.println("Not enough hallways!");
			else
				System.out.println(dis[a][b] * t);
		}
	}
}
