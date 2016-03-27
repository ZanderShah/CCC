package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class RomanticDinner
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int u = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());

		int[] v = new int[r + 1];
		int[] t = new int[r + 1];
		int[] f = new int[r + 1];

		for (int i = 1; i <= r; i++)
		{
			st = new StringTokenizer(br.readLine());
			v[i] = Integer.parseInt(st.nextToken());
			t[i] = Integer.parseInt(st.nextToken());
			f[i] = Integer.parseInt(st.nextToken());
		}

		int[][][] dp = new int[r + 1][m + 1][u + 1];
		
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= m; j++)
				for (int k = 1; k <= u; k++)
				{
					if (t[i] <= j && f[i] <= k)
						dp[i][j][k] = Math.max(dp[i - 1][j][k], dp[i - 1][j - t[i]][k - f[i]] + v[i]);
					else
						dp[i][j][k] = dp[i - 1][j][k];
				}
		
		System.out.println(dp[r][m][u]);
	}

}
