import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Nukit
{
	static int[][][][] dp;

	static int play(int a, int b, int c, int d, int t)
	{
		if (dp[a][b][c][d] != -1)
			return dp[a][b][c][d];

		int result = -1;

		if (t == 0)
			t = 1;
		else
			t = 0;

		if (a >= 2 && b >= 1 && d >= 2)
		{
			result = play(a - 2, b - 1, c, d - 2, t);
			if (result != t)
				if (t == 0)
					return dp[a][b][c][d] = 1;
				else
					return dp[a][b][c][d] = 0;
		}
		if (a >= 1 && b >= 1 && c >= 1 && d >= 1)
		{
			result = play(a - 1, b - 1, c - 1, d - 1, t);
			if (result != t)
				if (t == 0)
					return dp[a][b][c][d] = 1;
				else
					return dp[a][b][c][d] = 0;
		}
		if (c >= 2 && d >= 1)
		{
			result = play(a, b, c - 2, d -1, t);
			if (result != t)
				if (t == 0)
					return dp[a][b][c][d] = 1;
				else
					return dp[a][b][c][d] = 0;
		}
		if (b >= 3)
		{
			result = play(a, b - 3, c, d, t);
			if (result != t)
				if (t == 0)
					return dp[a][b][c][d] = 1;
				else
					return dp[a][b][c][d] = 0;
		}
		if (a >= 1 && d >= 1)
		{
			result = play(a - 1, b, c, d - 1, t);
			if (result != t)
				if (t == 0)
					return dp[a][b][c][d] = 1;
				else
					return dp[a][b][c][d] = 0;
		}

		return dp[a][b][c][d] = t;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for (int test = 0; test < t; test++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			dp = new int[a + 1][b + 1][c + 1][d + 1];
			for (int i = 0; i <= a; i++)
				for (int j = 0; j <= b; j++)
					for (int p = 0; p <= c; p++)
						for (int q = 0; q <= d; q++)
							dp[i][j][p][q] = -1;

			if (play(a, b, c, d, 0) == 0)
				System.out.println("Patrick");
			else
				System.out.println("Roland");
		}
	}
}
