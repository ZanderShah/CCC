package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class ClaireElstein
{
	static State[] dp;
	static int n, m;
	static ArrayList<Integer>[] adj;
	
	static class State
	{
		long num, sum;
		State()
		{
			num = sum = -1;
		}
	}
	
	static State go(int x)
	{
		if (dp[x].num != -1)
			return dp[x];
		
		dp[x].num = dp[x].sum = 0;
		if (adj[x].size() == 0)
			dp[x].num++;
		for (Integer i : adj[x])
		{
			dp[x].sum += go(i).num + go(i).sum;
			dp[x].num += go(i).num;
		}
		
		dp[x].sum %= 1000000007;
		dp[x].num %= 1000000007;
		
		return dp[x];
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		m = readInt();
		adj = new ArrayList[n];
		dp = new State[n];
		boolean[] start = new boolean[n];
		for (int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
			start[i] = true;
			dp[i] = new State();
		}

		for (int i = 0, a, b; i < m; i++)
		{
			a = readInt() - 1;
			b = readInt() - 1;
			adj[a].add(b);
			start[b] = false;
		}
		
		long ans = 0;
		for (int i = 0; i < n; i++)
			if (start[i])
				ans = (ans + go(i).sum) % 1000000007;
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
