import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class GreedyForPies
{
	public static int n, m;
	public static int[] p, x;
	public static int[][][][] dp;
	
	public static int eat(int a, int b, int l, int r)
	{
		int ret = dp[a][b][l][r];
		if (ret != -1)
			return ret;
		if (a == n + 1)
		{
			if (l <= r)
			{
				if (b == 1)
					return ret = x[r] + eat(a, 0, l, r - 1);
				return ret = eat(a, 1, l + 1, r);
			}
			return ret = 0;
		}
		if (b == 1)
		{
			ret = Math.max(eat(a, 0, l, r), p[a] + eat(a + 1, 0, l, r));
			if (l <= r)
				ret = Math.max(ret, x[r] + eat(a, 0, l, r - 1));
		}
		else 
		{
			ret = eat(a + 1, 1, l, r);
			if (l <= r)
				ret = Math.max(ret, eat(a, 1, l + 1, r));
		}
		
		return dp[a][b][l][r] = ret;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		p = new int[n + 1];
		
		for (int i = 1; i <= n; i++)
			p[i] = Integer.parseInt(br.readLine());
		
		m = Integer.parseInt(br.readLine());
		x = new int[m + 1];
		for (int i = 1; i <= m; i++)
			x[i] = Integer.parseInt(br.readLine());
		Arrays.sort(x);
		
		dp = new int[n + 5][2][m + 5][m + 5];
		for (int i = 0; i <= n + 4; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k <= m + 4; k++)
					for (int q = 0; q <= m + 4; q++)
						dp[i][j][k][q] = -1;
		
		System.out.println(eat(1, 1, 1, m));
	}

}
