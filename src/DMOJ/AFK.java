package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class AFK
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int cases = Integer.parseInt(br.readLine());

		for (int cas = 0; cas < cases; cas++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			char[][] g = new char[c][r];
			int x = 0;
			int y = 0;
			int eX = 0;
			int eY = 0;
			
			for (int i = 0; i < c; i++)
			{
				String s = br.readLine();
				for (int j = 0; j < r; j++)
				{
					g[i][j] = s.charAt(j);

					if (g[i][j] == 'C')
					{
						x = i;
						y = j;
						g[i][j] = 'O';
					}
					
					if (g[i][j] == 'W')
					{
						eX = i;
						eY = j;
						g[i][j] = 'O';
					}
				}
			}

			Queue<Integer[]> q = new LinkedList<Integer[]>();
			q.add(new Integer[] { x, y, 0 });
			boolean done = false;

			while (!q.isEmpty())
			{
				Integer[] cur = q.poll();

				int a = cur[0];
				int b = cur[1];
				
				if (cur[2] >= 60)
				{
					System.out.println("#notworth");
					done = true;
					break;
				}

				if (a == eX && b == eY)
				{
					System.out.println(cur[2]);
					done = true;
					break;
				}
				
				if (a + 1 < c && g[a + 1][b] != 'X')
				{
					q.add(new Integer[] { a + 1, b, cur[2] + 1 });
					g[a + 1][b] = 'X';
				}
				if (a - 1 >= 0 && g[a - 1][b] != 'X')
				{
					q.add(new Integer[] { a - 1, b, cur[2] + 1 });
					g[a - 1][b] = 'X';
				}
				if (b + 1 < r && g[a][b + 1] != 'X')
				{
					q.add(new Integer[] { a, b + 1, cur[2] + 1 });
					g[a][b + 1] = 'X';
				}
				if (b - 1 >= 0 && g[a][b - 1] != 'X')
				{
					q.add(new Integer[] { a, b - 1, cur[2] + 1 });
					g[a][b - 1] = 'X';
				}
			}

			if (!done)
				System.out.println("#notworth");

		}
	}

}
