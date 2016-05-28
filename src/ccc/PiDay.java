package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class PiDay
{
	public static int[][][] memo;

	/**
	 * Check all possibilities and memoize answers
	 * 
	 * @param n the number of pies
	 * @param k the number of people
	 * @param m the pie to be looked at
	 * @return the number of ways that the pieces can be given out
	 */
	public static int eat(int n, int k, int m)
	{
		if (memo[n][k][m] == 0)
			if (n == k || k == 1)
				memo[n][k][m] = 1;
			else
			{
				int pi = 0;
				for (int i = m; i < n / k + 1; i++)
					pi += eat(n - i, k - 1, i);
				memo[n][k][m] = pi;
			}
		
		return memo[n][k][m];
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());

		memo = new int[n + 1][k + 1][n + 1];

		System.out.println(eat(n, k, 1));
	}

}
