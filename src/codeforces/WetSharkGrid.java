package codeforces;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WetSharkGrid
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] c = new int[2016];
		int[] l = new int[2016];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			c[y - x + 1000]++;
			l[x + y]++;
		}

		int t = 0;

		for (int i = 0; i < 2016; i++)
		{
			t += (c[i] * (c[i] - 1)) / 2;
			t += (l[i] * (l[i] - 1)) / 2;
		}

		System.out.println(t);

	}

}
