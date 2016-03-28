package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// Incomplete
public class PickIt
{
	static int[] dp, k;
	static int n;
	static int solve(int x)
	{
		if (dp[x] != -1)
			return dp[x];
		
		int max = 0;
		
		return dp[x] = max;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(br.readLine());

		while (n != 0)
		{
			dp = new int[n];
			Arrays.fill(dp, -1);
			k = new int[n];
			for (int i = 0; i < n; i++)
				k[i] = Integer.parseInt(st.nextToken());

			System.out.println(solve(0));
			
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
		}
	}

}
