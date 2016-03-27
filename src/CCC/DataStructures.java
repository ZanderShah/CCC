package CCC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DataStructures
{
	static class Point implements Comparable<Point>
	{
		long x = -1, y, ans;

		public Point(long xx, long yy, long aa)
		{
			x = xx;
			y = yy;
			ans = aa;
		}

		public int compareTo(Point p)
		{
			return (int) (x - p.x);
		}
	}

	public static void main(String[] args) throws IOException
	{
		long n = readLong();
		int m = readInt();

		Point[] pts = new Point[m];
		for (int i = 0; i < m; i++)
		{
			long y = n - readLong() + 1;
			long x = readLong();
			pts[i] = new Point(x, y, y * (y + 1) / 2);
		}

		Arrays.sort(pts);

		for (int i = 0; i < m; i++)
		{
			long la = pts[i].x;
			long ra = pts[i].x + pts[i].y - 1;

			for (int j = i + 1; j < m; j++)
			{
				long lb = pts[j].x;
				long rb = pts[j].x + pts[j].y - 1;

				if (ra >= lb)
					if ((la <= lb && ra >= rb) || (lb <= la && rb >= ra))
						if (pts[i].y * (pts[i].y + 1) / 2 < pts[j].y
								* (pts[j].y + 1) / 2)
							pts[i].ans = Integer.MIN_VALUE;
						else
							pts[j].ans = Integer.MIN_VALUE;
					else if (pts[j].x - pts[i].x <= pts[i].y)
						pts[i].ans -= (pts[i].y - pts[j].x + pts[i].x)
								* (pts[i].y - pts[j].x + pts[i].x + 1) / 2;
			}
		}

		long total = 0;
		for (Point p : pts)
			total += Math.max(0, p.ans);

		System.out.println(total);
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
