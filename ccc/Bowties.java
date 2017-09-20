package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Bowties
{
	static int n;
	static ArrayList<Integer>[] pts;

	static class points implements Comparable<points>
	{
		int x, y;

		public points(int xx, int yy)
		{
			x = xx;
			y = yy;
		}

		public int compareTo(points p)
		{
			return x - p.x;
		}
	}

	static class points2 implements Comparable<points2>
	{
		int x, y;

		public points2(int xx, int yy)
		{
			x = xx;
			y = yy;
		}

		public int compareTo(points2 p)
		{
			return y - p.y;
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		points[] pts = new points[n];
		points2[] pts2 = new points2[n];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			pts[i] = new points(a, b);
			pts2[i] = new points2(a, b);
		}

		Arrays.sort(pts);
		Arrays.sort(pts2);

		ArrayList<Integer>[] ex = new ArrayList[n];
		ArrayList<Integer>[] ey = new ArrayList[n];
		HashMap<Integer, Integer> yMap = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> xMap = new HashMap<Integer, Integer>();

		for (int i = 0; i < n; i++)
		{
			ex[i] = new ArrayList<Integer>();
			ey[i] = new ArrayList<Integer>();
		}

		
		xMap.put(0, pts[0].x);
		int ind1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || pts[i].x == pts[i - 1].x)
				ex[ind1].add(pts[i].y);
			else
			{
				ind1++;
				ex[ind1].add(pts[i].y);
				xMap.put(ind1, pts[i].x);
			}
		}
		
		yMap.put(pts2[0].y, 0);
		int ind2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (i == 0 || pts2[i].y == pts2[i - 1].y)
				ey[ind2].add(pts2[i].x);
			else
			{
				ind2++;
				ey[ind2].add(pts2[i].x);
				yMap.put(pts2[i].y, ind2);
			}
		}

		for (int i = 0; i < n; i++)
		{
			Collections.sort(ex[i]);
			Collections.sort(ey[i]);
		}

		long ans = 0;

		for (int i = 1; i < ind1; i++)
			if (ex[i].size() >= 3)
			{
				for (int j = 1; j < ex[i].size() - 1; j++)
				{		
					int s = Collections.binarySearch(ey[yMap.get(ex[i].get(j))], xMap.get(i));
					
					long l = s;
					long r = ey[yMap.get(ex[i].get(j))].size() - 1 - s;
					long d = j;
					long u = ex[i].size() - j - 1;

					long possD1 = l * d;
					long possD2 = r * d;
					long possU1 = u * r;
					long possU2 = u * l;

					ans += possD1 * possU1 + possD2 * possU2;
				}
			}

		System.out.println(ans);
	}
}
