package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class PizzaBag
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), k = readInt();

		int[] s = new int[n];

		for (int i = 0; i < n; i++)
			s[i] = readInt();

		long[] p = new long[2 * n + 1];

		for (int i = 0; i <= 2 * n; i++)
		{
			p[i] = s[i % n];
			if (i != 0)
				p[i] += p[i - 1];
		}
		
		TreeMap<Long, Integer> t = new TreeMap<Long, Integer>();
		
		for (int i = 0; i <= k; i++)
			if (t.containsKey(p[i]))
				t.replace(p[i], t.get(p[i]) + 1);
			else
				t.put(p[i], 1);
		
		long[] max = new long[n];
		
		for (int i = 0; i < n; i++)
		{
			max[i] = t.floorKey(Long.MAX_VALUE);
		
			if (t.get(p[i]) > 1)
				t.replace(p[i], t.get(p[i]) - 1);
			else
				t.remove(p[i]);
			
			if (t.containsKey(p[i + k + 1]))
				t.replace(p[i + k + 1], t.get(p[i + k + 1]) + 1);
			else
				t.put(p[i + k + 1], 1);
		}
		
		long ans = 0;
		
		for (int i = 0; i < n; i++)
			ans = Math.max(ans, max[i] - p[i]);
		
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
