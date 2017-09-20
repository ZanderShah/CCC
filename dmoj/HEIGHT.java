package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class HEIGHT
{
	static int n, a[], dp[][];

	static int go(int x, int y)
	{
		if (x == n)
			return 0;

		if (dp[x][y] != -1)
			return dp[x][y];

		int ret = 0;
		if (a[x] > y)
			ret = Math.max(ret, a[x] + go(x + 1, a[x]));
		ret = Math.max(ret, go(x + 1, y));

		return dp[x][y] = ret;
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = readInt();

		dp = new int[n][1001];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 1001; j++)
				dp[i][j] = -1;

		int max = 0;
		for (int r = 0; r < n; r++)
			max = Math.max(max, go(r, 0));

		System.out.println(max);
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}

}
