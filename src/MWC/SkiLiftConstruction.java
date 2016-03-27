package MWC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SkiLiftConstruction
{
	static class Cable
	{
		int ax, ay, bx, by;

		Cable(int a, int b, int c, int d)
		{
			ax = a;
			ay = b;
			bx = c;
			by = d;
		}
	}

	static ArrayList<Cable> cables = new ArrayList<Cable>();

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int[] h = new int[n];
		ArrayList<Cable> cables = new ArrayList<Cable>();
		h[0] = readInt();
		for (int i = 1; i < n; i++)
		{
			h[i] = readInt();
			cables.add(new Cable(i - 1, h[i - 1], i, h[i]));
			
			for (int j = Math.max(0, cables.size() - 2); j < cables.size() - 1 && j >= 0; j++)
			{
				Cable a = cables.get(j);
				Cable c = cables.get(j + 1);

				double m = (c.by - a.ay) * 1.0 / (c.bx - a.ax);
				double b = a.ay - m * a.ax;

				if (m * a.bx + b >= a.by)
				{
					c.ax = a.ax;
					c.ay = a.ay;
					cables.remove(j);
					j -= 2;
				}
			}
		}

		double ans = 0;

		for (int i = 0; i < cables.size(); i++)
		{
			Cable a = cables.get(i);
			ans += Math.sqrt((a.ax - a.bx) * (a.ax - a.bx)
					+ (a.ay - a.by) * (a.ay - a.by));
		}

		System.out.println(ans);
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
