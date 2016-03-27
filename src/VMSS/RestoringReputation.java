package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RestoringReputation
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int d = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());

		String[] t = br.readLine().split(" ");

		String a = t[0];
		String b;
		
		if (t.length > 1)
			b = t[1];
		else
			b = br.readLine();
		
		int[][] dp = new int[a.length() + 1][b.length() + 1];

		for (int i = 0; i <= a.length(); i++)
			dp[i][0] = i * d;

		for (int j = 0; j <= b.length(); j++)
			dp[0][j] = j * q;

		for (int i = 0; i < a.length(); i++)
		{
			char m = a.charAt(i);
			for (int j = 0; j < b.length(); j++)
			{
				char n = b.charAt(j);

				if (m == n)
					dp[i + 1][j + 1] = dp[i][j];
				else
					dp[i + 1][j + 1] = Math.min(Math.min(dp[i][j] + r,
							dp[i][j + 1] + d), dp[i + 1][j] + q);
			}
		}

		System.out.println(dp[a.length()][b.length()]);
	}
}