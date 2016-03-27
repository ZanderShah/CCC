package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JaydenChocolate
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int z = Integer.parseInt(st.nextToken());

		int[] dp = new int[n + 1];

		for (int i = 1; i <= n; i++)
		{
			if (i >= x && (i - x == 0 || dp[i - x] != 0))
				dp[i] = Math.max(dp[i], dp[i - x] + 1);
			if (i >= y && (i - y == 0 || dp[i - y] != 0))
				dp[i] = Math.max(dp[i], dp[i - y] + 1);
			if (i >= z && (i - z == 0 || dp[i - z] != 0))
				dp[i] = Math.max(dp[i], dp[i - z] + 1);
		}

		System.out.println(dp[n]);
	}

}
