package ccc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class PinballRanking
{
	static long sum[];

	static void update(int x, long v)
	{
		for (; x <= n; x += (x & (-x)))
			sum[x] += v;
	}

	static long query(int r)
	{
		long ans = 0;
		while (r > 0)
		{
			ans += sum[r];
			r -= (r & (-r));
		}

		return ans;
	}

	static int n;

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		sum = new long[n + 1];
		int[] val = new int[n], sort = new int[n];

		for (int i = 0; i < n; i++)
			val[i] = sort[i] = readInt();

		Arrays.sort(sort);
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		map.put(sort[n - 1], 1);
		int j = 2;
		for (int i = n - 2; i >= 0; i--)
			if (sort[i] != sort[i + 1])
				map.put(sort[i], j++);

		long t = 0;

		for (int i = 1; i <= n; i++)
		{
			t += query(map.get(val[i - 1]) - 1) + 1;
			update(map.get(val[i - 1]), 1);
		}

		double a = Math.round((t * 1.0 / n) * 100) / 100.0;
		System.out.printf("%.2f", a);
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