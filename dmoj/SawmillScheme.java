package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class SawmillScheme
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		ArrayList<Integer>[] lakes = new ArrayList[n];
		for (int i = 0; i < n; i++)
			lakes[i] = new ArrayList<Integer>();
		
		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			lakes[a].add(b);
		}

		double[] dp = new double[n];
		dp[0] = 1;

		for (int i = 0; i < n; i++)
		{
			double c = dp[i] / lakes[i].size();
			for (Integer j : lakes[i])
				dp[j] += c;
		}

		for (int i = 0; i < n; i++)
			if (lakes[i].size() == 0)
				System.out.println(dp[i]);
	}

}
