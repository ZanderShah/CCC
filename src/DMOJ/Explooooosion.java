package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Explooooosion
{
	static int m;

	static long power(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % m) * (x % m))
			if ((n >> i & 1) != 0)
				a = (a % m) * (x % m);
		return a % m;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		m = 1000000007;

		int[] p = new int[1002];
		for (int i = 0; i < n; i++)
			p[readInt()]++;

		long min = 0;
		for (int i = 2; i <= 1000; i++)
			min = (min + (p[i] * i) % m) % m;

		System.out.println((min == 0 ? 1 : min));

		long max = 1;

		int loss = Math.min(p[1], p[2]);
		p[3] += loss;
		p[2] -= loss;
		p[1] -= loss;

		loss = p[1] / 3;
		p[3] += loss;
		p[1] -= loss * 3;
		
		if (p[1] == 2)
			p[2]++;
		else if (p[1] == 1)
			for (int i = 2; i <= 1000; i++)
				if (p[i] != 0)
				{
					p[i + 1]++;
					p[i]--;
					break;
				}

		for (int i = 2; i <= 1001; i++)
			max = (max * power(i, p[i])) % m;

		System.out.println(max);
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
