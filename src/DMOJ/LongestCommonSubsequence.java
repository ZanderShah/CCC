package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class LongestCommonSubsequence
{
	public static void main(String[] arge) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int[] j = new int[n];
		int m = Integer.parseInt(st.nextToken());
		int[] l = new int[m];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			j[i] = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++)
			l[i] = Integer.parseInt(st.nextToken());

		int[][] ans = new int[2][m + 1];
		
		for (int i = 1; i <= n; i++)
		{
			for (int q = 1; q <= m; q++)
			{
				if (j[i - 1] == l[q - 1])
					ans[1][q] = ans[0][q - 1] + 1;
				else
					ans[1][q] = Math.max(ans[1][q - 1], ans[0][q]);
			}
			
			for (int r = 1; r <= m; r++)
				ans[0][r] = ans[1][r];
			Arrays.fill(ans[1], 0);
			
			if (i == n)
				System.out.println(ans[0][m]);
		}
	}
}
