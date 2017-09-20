package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SignalHill
{
	public static boolean[][] ans, g;;
	public static int beacon;

	public static void fill(int s, int i)
	{
		ans[s][i] = true;
		
		for (int j = 0; j < beacon; j++)
			if (g[i][j] && !ans[s][j])
				fill(s, j);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		beacon = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		int[][] b = new int[beacon][3];
		g = new boolean[beacon][beacon];
		ans = new boolean[beacon][beacon];

		for (int i = 0; i < beacon; i++)
		{
			st = new StringTokenizer(br.readLine());
			b[i][0] = Integer.parseInt(st.nextToken());
			b[i][1] = Integer.parseInt(st.nextToken());
			b[i][2] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < beacon; i++)
			for (int j = 0; j < beacon; j++)
				if ((b[i][0] - b[j][0]) * (b[i][0] - b[j][0])
						+ (b[i][1] - b[j][1]) * (b[i][1] - b[j][1]) <= b[j][2]
						* b[j][2])
					g[j][i] = true;

		for (int i = 0; i < beacon; i++)
			fill(i, i);

		for (int i = 0; i < q; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			if (ans[a - 1][c - 1])
				System.out.println("YES");
			else
				System.out.println("NO");
		}

	}

}
