import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Switch
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int k = Integer.parseInt(br.readLine());
		String light = "";

		for (int i = 0; i < k; i++)
			light += br.readLine();

		int c = Integer.parseInt(light, 2);

		byte[] dp = new byte[(int) Math.pow(2, k)];
		Arrays.fill(dp, Byte.MAX_VALUE);
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(c);
		dp[c] = 0;

		while (!q.isEmpty())
		{
			int t = q.poll();
			int d = dp[t];

			if (t == 0)
			{
				System.out.println(d);
				break;
			}

			for (int i = 0; i < k; i++)
				if ((t & (1 << i)) == 0)
				{
					int newT = t + (int) Math.pow(2, i);

					int l = i - 1;
					int r = i + 1;

					while (l >= 0 && (newT & (1 << l)) != 0)
						l--;
					while (r < k && (newT & (1 << r)) != 0)
						r++;

					if (r - l - 1 >= 4)
						for (int j = l + 1; j < r; j++)
							newT -= Math.pow(2, j);

					if (dp[newT] == Byte.MAX_VALUE)
					{
						q.add(newT);
						dp[newT] = (byte) (d + 1);
					}
				}
		}
	}

}
