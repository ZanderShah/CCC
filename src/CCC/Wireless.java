package CCC;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Wireless
{

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int m = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());

		int[][] g = new int[m + 1][n + 1];

		for (int i = 0; i < k; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken()) - 1;
			int q = Integer.parseInt(st.nextToken()) - 1;
			int r = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			for (int j = Math.max(q - r, 0); j <= Math.min(m - 1, q + r); j++)
			{
				int x1 = Math.max(0,
						p - (int) (Math.sqrt(r * r - (j - q) * (j - q))));
				int x2 = Math.min(n - 1,
						p + (int) (Math.sqrt(r * r - (j - q) * (j - q))));

				g[j][x1] += b;
				g[j][x2 + 1] -= b;
			}
		}

		int c = 0;
		int max = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j != 0)
					g[i][j] += g[i][j - 1];
				if (g[i][j] > max)
				{
					max = g[i][j];
					c = 1;
				}
				else if (g[i][j] == max)
					c++;
			}
		}

		System.out.println(max);
		System.out.println(c);

	}
}
