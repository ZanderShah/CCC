package cco;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Artsjki
{
	public static int n;
	public static int[][] towns, dp;
	public static boolean[] vis;
	public static boolean works = false;

	/**
	 * Semi-brute force approach which checks lengths but keeps track of the longest
	 * path given a specific state defined by the binary representation of the current
	 * path
	 * 
	 * @param c the current node
	 * @param s the current state of the solution
	 * @return the maximum possible length from that state onwards
	 */
	public static int go(int c, int s)
	{
		if (c == n - 1)
			return 0;

		if (dp[c][s] != -1)
			return dp[c][s];

		int max = -1000000000;

		for (int i = 0; i < n; i++)
			if (!vis[i] && towns[c][i] != 0)
			{
				vis[i] = true;
				
				max = Math.max(max, go(i, s + (int) Math.pow(2, i))
						+ towns[c][i]);
				
				vis[i] = false;
			}

		return dp[c][s] = max;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		dp = new int[n][(int) Math.pow(2, n)];
		for (int i = 0; i < n; i++)
			Arrays.fill(dp[i], -1);

		towns = new int[n][n];

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			towns[a][b] = d;
		}

		vis = new boolean[n];
		vis[0] = true;
		
		System.out.println(go(0, 1));
	}

}