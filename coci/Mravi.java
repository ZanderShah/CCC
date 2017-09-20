package coci;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Mravi
{
	static class Path
	{
		int b, x, t;

		Path(int bb, int xx, int tt)
		{
			b = bb;
			x = xx;
			t = tt;
		}
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		ArrayList<Path>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<Path>();
		for (int i = 0, a, b, x, t; i < n - 1; i++)
		{
			a = readInt() - 1;
			b = readInt() - 1;
			x = readInt();
			t = readInt();
			adj[Math.max(a, b)].add(new Path(Math.min(a, b), x, t));
		}

		double[] min = new double[n];
		Queue<Integer> q = new LinkedList<Integer>();

		for (int i = 0, k; i < n; i++)
		{
			k = readInt();
			if (k != -1)
			{
				min[i] = k;
				q.add(i);
			}
		}

		while (!q.isEmpty())
		{
			int x = q.poll();

			for (Path p : adj[x])
			{
				if (p.t == 1)
				{
					double a = Math.sqrt(min[x]) * 100 / p.x;
					double b = min[x] * 100 / p.x;
					min[p.b] = Math.max(min[p.b], Math.min(a, b));
				}
				else
					min[p.b] = Math.max(min[p.b], min[x] * 100 / p.x);

				q.add(p.b);
			}
		}

		System.out.println(min[0]);
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
