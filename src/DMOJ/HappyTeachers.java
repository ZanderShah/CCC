package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// Solved for maximum happiness but not minimum seconds
// I might have to do a non-recursive dp
public class HappyTeachers
{
	static int n, s, best, time = Integer.MAX_VALUE;
	static int[] h, e, p;
	static int[][] dp;

	static int solve(int x, int m)
	{
		if (x > n)
			return 0;
		if (dp[x][m] != -1)
			return dp[x][m];

		int best = 0;
		for (int i = 1, val = h[x], cur = h[x]; cur > 0 && m + p[x] * i <= s; i++, cur -= e[x], val += cur)
			best = Math.max(best, solve(x + 1, m + p[x] * i) + val);
		best = Math.max(best, solve(x + 1, m));
		return dp[x][m] = best;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		n = Integer.parseInt(br.readLine());

		h = new int[n + 1];
		e = new int[n + 1];
		p = new int[n + 1];

		for (int i = 1; i <= n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			h[i] = Integer.parseInt(st.nextToken());
			e[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}

		s = Integer.parseInt(br.readLine());
		dp = new int[n + 1][s + 1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= s; j++)
				dp[i][j] = -1;

		solve(1, 0);
		System.out.println(best);
		System.out.println(time);
	}

}
