package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BatDoctor
{

	static class Point implements Comparable<Point>
	{
		int x, y;

		Point(int xx, int yy)
		{
			x = xx;
			y = yy;
		}

		public int compareTo(Point p)
		{
			return x - p.x;
		}
	}

	public static void main(String[] args) throws Exception
	{
		int r = readInt();
		int c = readInt();
		boolean[][] g = new boolean[r][c];
		ArrayList<Point> points = new ArrayList<Point>();
		double ans;

		for (int i = 0; i < r; i++)
		{
			String s = readLine();
			for (int j = 0; j < c; j++)
			{
				g[i][j] = s.charAt(j) == 'X';
				if (g[i][j])
					points.add(new Point(j, i));
			}
		}

		Collections.sort(points);

		if (points.isEmpty())
			System.out.println("0.000");
		else
			for (int i = 0; i < points.size() - 1; i++)
			{
				Point a = points.get(i);
				Point b = points.get(i + 1);

				if (a.y < b.y)
					ans = 180 - Math.atan(Math.abs(a.x - b.x) * 1.0
							/ Math.abs(a.y - b.y)) * 180 / Math.PI;
				else
					ans = Math.atan(Math.abs(a.x - b.x) * 1.0
							/ Math.abs(a.y - b.y))
							* 180 / Math.PI;

				System.out.println(Math.round(ans * 1000) / 1000.0);
			}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}

}
