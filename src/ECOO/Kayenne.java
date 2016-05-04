package ECOO;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Kayenne
{

	static class Point
	{
		int x, y;
		char a;

		Point(int xx, int yy, char aa)
		{
			x = xx;
			y = yy;
			a = aa;
		}
	}

	static class Dist implements Comparable<Dist>
	{
		long d;
		char a;

		Dist(long dd, char aa)
		{
			d = dd;
			a = aa;
		}

		public int compareTo(Dist da)
		{
			return ((Long) d).compareTo(da.d);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int testCase = 0; testCase < 10; testCase++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int cx = Integer.parseInt(st.nextToken());
			int cy = Integer.parseInt(st.nextToken());
			Point[] p = new Point[100];
			boolean[][] poss = new boolean[500][500];

			for (int i = 0; i < 100; i++)
			{
				st = new StringTokenizer(br.readLine());
				p[i] = new Point(Integer.parseInt(st.nextToken()),
						Integer.parseInt(st.nextToken()),
						st.nextToken().charAt(0));
				poss[p[i].x + 250][p[i].y + 250] = true;
			}

			int dCount = 0;
			int tCount = 0;

			for (int x = cx - 50; x <= cx + 50; x++)
				for (int y = cy - 50; y <= cy + 50; y++)
					if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= 2500
							&& !poss[x + 250][y + 250])
					{
						ArrayList<Dist> d = new ArrayList<Dist>();
						for (int i = 0; i < p.length; i++)
						{
							d.add(new Dist((x - p[i].x) * (x - p[i].x)
									+ (y - p[i].y) * (y - p[i].y), p[i].a));
						}

						Collections.sort(d);

						int dem = 0, rep = 0;

						for (int i = 0; i < d.size()
								&& (i < 3 || d.get(i).d == d.get(i - 1).d); i++)
						{
							if (d.get(i).a == 'D')
								dem++;
							else
								rep++;
						}

						if (dem >= rep)
							dCount++;
						tCount++;
					}

			System.out.printf("%.1f%n", (double) dCount / tCount * 100);
		}
	}
}