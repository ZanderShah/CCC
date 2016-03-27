package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class NotEnoughTime
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());

		int[][] p = new int[n + 1][3];
		int[][] v = new int[n + 1][3];

		for (int i = 1; i <= n; i++)
		{
			st = new StringTokenizer(br.readLine());
			p[i][0] = Integer.parseInt(st.nextToken());
			v[i][0] = Integer.parseInt(st.nextToken());
			p[i][1] = Integer.parseInt(st.nextToken());
			v[i][1] = Integer.parseInt(st.nextToken());
			p[i][2] = Integer.parseInt(st.nextToken());
			v[i][2] = Integer.parseInt(st.nextToken());
		}

		int[] prev = new int[t + 1];
		int[] next = new int[t + 1];

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= t; j++)
			{
				if (p[i][0] <= j)
					next[j] = Math.max(next[j],
							Math.max(prev[j], prev[j - p[i][0]] + v[i][0]));
				if (p[i][1] <= j)
					next[j] = Math.max(next[j],
							Math.max(prev[j], prev[j - p[i][1]] + v[i][1]));
				if (p[i][2] <= j)
					next[j] = Math.max(next[j],
							Math.max(prev[j], prev[j - p[i][2]] + v[i][2]));
				if (next[j] == 0)
					next[j] = prev[j];
			}
			
			prev = next.clone();
			next = new int[t + 1];
		}

		System.out.println(prev[t]);

	}

}
