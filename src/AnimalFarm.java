import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * My own implementation of the solution found on mmhs to see if I understand it
 */
public class AnimalFarm
{
	static int[][] weight;

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		// info[][][0] for the animal that could be in the pen (-1 for no animal)
		// info[][][1] for the weight at that edge
		int[][][] info = new int[1001][1001][2];
		for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 1001; j++)
				info[i][j][0] = -1;

		int n = Integer.parseInt(br.readLine());;

		weight = new int[n + 1][n + 1];
		for (int i = 0; i <= n; i++)
			Arrays.fill(weight[i], Integer.MAX_VALUE);
		for (int j = 0; j <= n; j++)
			weight[j][j] = 0;

		for (int i = 0, e; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			e = Integer.parseInt(st.nextToken());
			int[] a = new int[e];
			int[] c = new int[e];
			for (int k = 0; k < e; k++)
				a[k] = Integer.parseInt(st.nextToken());
			for (int k = 0; k < e; k++)
				c[k] = Integer.parseInt(st.nextToken());

			for (int j = 0; j < e; j++)
			{
				int k = (j + 1) % e;

				if (info[a[j]][a[k]][1] > 0)
				{
					if (weight[i][info[a[j]][a[k]][0]] > c[j])
					{
						weight[i][info[a[j]][a[k]][0]] = c[j];
						weight[info[a[j]][a[k]][0]][i] = c[j];
					}
					info[a[j]][a[k]][0] = -1;
					info[a[k]][a[j]][0] = -1;
				}
				else
				{
					info[a[j]][a[k]][1] = c[j];
					info[a[j]][a[k]][0] = i;
					info[a[k]][a[j]][1] = c[j];
					info[a[k]][a[j]][0] = i;
				}
			}
		}

		for (int i = 0; i < 1001; i++)
			for (int j = 0; j < 1001; j++)
				if (info[i][j][0] >= 0)
				{
					if (weight[info[i][j][0]][n] > info[i][j][1])
					{
						weight[info[i][j][0]][n] = info[i][j][1];
						weight[n][info[i][j][0]] = info[i][j][1];
					}
				}

		int notOutside = prims(n);
		int outSide = prims(n + 1);

		System.out.println(Math.min(notOutside, outSide));
	}

	public static int prims(int n)
	{
		int u = Integer.MAX_VALUE;
		int[] val = new int[n + 1];
		for (int k = 1; k <= n; k++)
			val[k] = -u;
		val[0] = -u - 1;
		int min = 1;
		int k;
		do
		{
			k = min;
			val[k] = -val[k];
			min = 0;
			if (val[k] == u)
				val[k] = 0;
			for (int t = 1; t <= n; t++)
			{
				if (val[t] < 0)
				{
					if (weight[k - 1][t - 1] != Integer.MAX_VALUE
							&& val[t] < -(weight[k - 1][t - 1]))
						val[t] = -(weight[k - 1][t - 1]);
					if (val[t] > val[min])
						min = t;
				}
			}
		}
		while (min != 0);

		int t = 0;
		for (int i = 1; i <= n; i++)
			t += val[i];
		return t;
	}
}
