package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class JoeyAndBiology
{
	public static String joey, animal;
	public static int n, m;
	public static int[][] dp;
	
	public static int solve(int j, int a)
	{	
		while(j < n && a < m && joey.charAt(j) == animal.charAt(a))
		{
			j++;
			a++;
		}

		if (j >= n && a >= m)
			return 0;
		if (j >= n)
			return (int)Math.ceil((m - a) * 1.0 / 3);
		if (a >= m)
			return (int)Math.ceil((n - j) * 1.0 / 3);
		
		if (dp[j][a] != -1)
			return dp[j][a];
		
		int min = Math.min(10000, solve(j, a + 1) + 1);
		min = Math.min(min, solve(j, a + 2) + 1);
		min = Math.min(min, solve(j, a + 3) + 1);
		min = Math.min(min, solve(j + 1, a) + 1);
		min = Math.min(min, solve(j + 2, a) + 1);
		min = Math.min(min, solve(j + 3, a) + 1);
		min = Math.min(min, solve(j + 1, a + 1) + 1);
		
		return dp[j][a] = min;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

	    joey = br.readLine();
		animal = br.readLine();
		
		dp = new int[n + 1][m + 1];
		for (int i = 0; i < n + 1; i++)
			Arrays.fill(dp[i], -1);

		System.out.println(solve(0, 0));
	}
}
