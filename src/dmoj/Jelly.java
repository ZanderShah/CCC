package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Jelly
{
	public static int xM, yM, zM, min, sX, sY, sZ;
	public static int[][][] jelly, best;

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		xM = Integer.parseInt(st.nextToken());
		yM = Integer.parseInt(st.nextToken());
		zM = Integer.parseInt(st.nextToken());
		min = Integer.MAX_VALUE;

		jelly = new int[zM][yM][xM];
		best = new int[zM][yM][xM];

		for (int i = 0; i < zM; i++)
			for (int j = 0; j < yM; j++)
			{
				String s = br.readLine();
				for (int k = 0; k < xM; k++)
				{
					if (s.charAt(k) == 'J')
					{
						sZ = i;
						sY = j;
						sX = k;
						jelly[i][j][k] = 0;
					}
					else
						jelly[i][j][k] = s.charAt(k) - '0';

					best[i][j][k] = Integer.MAX_VALUE;
				}
			}

		Queue<Integer[]> q = new LinkedList<Integer[]>();
		q.add(new Integer[] { sZ, sY, sX, 0 });

		while (!q.isEmpty())
		{
			Integer[] cur = q.poll();
			int z = cur[0];
			int y = cur[1];
			int x = cur[2];
			int d = cur[3];

			if (d < min)
				if ((z == 0 || y == 0 || x == 0 || z == xM - 1 || y == yM - 1
						|| x == xM - 1))
					min = d;
				else if (d <= best[z][y][x])
				{
					if (z - 1 >= 0
							&& d + jelly[z - 1][y][x] < best[z - 1][y][x]
							&& d + jelly[z - 1][y][x] < min)
					{
						best[z - 1][y][x] = d + jelly[z - 1][y][x];
						q.add(new Integer[] { z - 1, y, x,
								d + jelly[z - 1][y][x] });
					}

					if (y - 1 >= 0
							&& d + jelly[z][y - 1][x] < best[z][y - 1][x]
							&& d + jelly[z][y - 1][x] < min)
					{
						best[z][y - 1][x] = d + jelly[z][y - 1][x];
						q.add(new Integer[] { z, y - 1, x,
								d + jelly[z][y - 1][x] });
					}

					if (x - 1 >= 0
							&& d + jelly[z][y][x - 1] < best[z][y][x - 1]
							&& d + jelly[z][y][x - 1] < min)
					{
						best[z][y][x - 1] = d + jelly[z][y][x - 1];
						q.add(new Integer[] { z, y, x - 1,
								d + jelly[z][y][x - 1] });
					}

					if (z + 1 < zM
							&& d + jelly[z + 1][y][x] < best[z + 1][y][x]
							&& d + jelly[z + 1][y][x] < min)
					{
						best[z + 1][y][x] = d + jelly[z + 1][y][x];
						q.add(new Integer[] { z + 1, y, x,
								d + jelly[z + 1][y][x] });
					}

					if (y + 1 < yM
							&& d + jelly[z][y + 1][x] < best[z][y + 1][x]
							&& d + jelly[z][y + 1][x] < min)
					{
						best[z][y + 1][x] = d + jelly[z][y + 1][x];
						q.add(new Integer[] { z, y + 1, x,
								d + jelly[z][y + 1][x] });
					}

					if (x + 1 < xM
							&& d + jelly[z][y][x + 1] < best[z][y][x + 1]
							&& d + jelly[z][y][x + 1] < min)
					{
						best[z][y][x + 1] = d + jelly[z][y][x + 1];
						q.add(new Integer[] { z, y, x + 1,
								d + jelly[z][y][x + 1] });
					}
				}
		}
		System.out.println(min);

	}
}