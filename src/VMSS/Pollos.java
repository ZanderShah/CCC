package VMSS;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Pollos
{
	static boolean works(int x)
	{
		int lastStop = 0;
		int stops = 0;
		for (int i = 0; i < n; i++)
		{
			if (stops >= k)
				return false;

			if (dist[i] - lastStop > x)
			{
				lastStop = dist[i - 1];
				stops++;
			}

			if (req[i])
			{
				lastStop = dist[i];
				stops++;
			}
		}

		return stops <= k;
	}

	static int n, k, dist[];
	static boolean req[];

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		k = readInt();
		dist = new int[n];
		req = new boolean[n];
		int min = 0;
		int d = 0;

		for (int i = 0; i < n; i++)
		{
			dist[i] = readInt();
			req[i] = readInt() == 1 || i + 1 == n;
			if (req[i])
				min++;

			if (i == 0)
				d = dist[i];
			else
				d = Math.max(d, dist[i] - dist[i - 1]);
		}

		if (min <= k)
		{
			int u = dist[dist.length - 1];
			int m = (u + d) / 2;

			for (; m != d; m = (u + d) / 2)
				if (works(m))
					u = m;
				else
					d = m;

			if (works(u) && works(d))
				System.out.println(d);
			else if (works(u))
				System.out.println(u);
			else
				System.out.println(d);
		}
		else
			System.out.println("DEA Bust!");
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
