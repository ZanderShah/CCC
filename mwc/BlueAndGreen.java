package mwc;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BlueAndGreen
{
	static int n, m, a, b, c, d, ans = 0;
	static int dp[];

	static void go(int v, int k)
	{
		if (dp[v] == 101)
			ans++;

		dp[v] = k;

		if (k + a <= m)
			for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
				if ((v & x) != 0 && dp[v - x] > k + a)
					go(v - x, k + a);
				else if ((v & x) == 0 && dp[v + x] > k + a)
					go(v + x, k + a);

		if (k + b <= m)
			if ((v & (1 << (n - 1))) != 0
					&& dp[((v - (1 << (n - 1))) << 1) + 1] > k + b)
				go(((v - (1 << (n - 1))) << 1) + 1, k + b);
			else if ((v & (1 << (n - 1))) == 0 && dp[v << 1] > k + b)
				go(v << 1, k + b);

		if (k + c <= m)
			if ((v & 1) != 0 && dp[(v >> 1) + (1 << n - 1)] > k + c)
				go((v >> 1) + (1 << n - 1), k + c);
			else if ((v & 1) == 0 && dp[v >> 1] > k + c)
				go(v >> 1, k + c);

		if (k + d <= m)
		{
			int o = v;
			for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
				if ((v & x) != 0)
					o -= x;
				else
					o += x;

			if (dp[o] > k + d)
				go(o, k + d);
		}
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		m = readInt();
		a = readInt();
		b = readInt();
		c = readInt();
		d = readInt();

		dp = new int[1 << n];
		Arrays.fill(dp, 101);

		String s = readLine();
		int v = 0;
		for (int i = 0, x = 1 << (n - 1); i < n; i++, x /= 2)
			if (s.charAt(i) == 'B')
				v += x;

		go(v, 0);
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