package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Nightmareathon
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		int[][] a = new int[n][10];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
		{
			int t = Integer.parseInt(st.nextToken()) - 1;
			a[i][t]++;
		}
		
		for (int i = 1; i < n; i++)
			for (int j = 0; j < 10; j++)
			{
				a[i][j] += a[i - 1][j];
			}
		
		for (int i = 0; i < q; i++)
		{
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken()) - 1;
			int e = Integer.parseInt(st.nextToken()) - 1;
			
			if (s != 0 && e != n - 1)
			{
				for (int j = 9; j >= 0; j--)
				{
					if (a[n - 1][j] - a[e][j] + a[s - 1][j] > 0)
					{
						System.out.println((j + 1) + " " + (a[n - 1][j] - a[e][j]  + a[s - 1][j]));
						break;
					}
				}
			}
			else if (e == n - 1 && s != 0)
			{
				for (int j = 9; j >= 0; j--)
				{
					if (a[s - 1][j] > 0)
					{
						System.out.println((j + 1) + " " + a[s - 1][j]);
						break;
					}
				}
			}
			else
			{
				for (int j = 9; j >= 0; j--)
				{
					if (a[n - 1][j] - a[e][j] > 0)
					{
						System.out.println((j + 1) + " " + (a[n - 1][j] - a[e][j]));
						break;
					}
				}
			}

		}
	}

}
