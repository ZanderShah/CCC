package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class MMORPG
{
	static ArrayList<Integer> adj[];
	static int[] size;
	static long ans = 1, dp[], f[];

	static int fillSize(int x)
	{
		int ret = 1;
		for (int i : adj[x])
			if (size[i] != 0)
				ret += size[i];
			else
				ret += fillSize(i);
		return size[x] = ret;
	}

	static long dfs(int x)
	{
		if (dp[x] != 0)
			return dp[x];

		int s = size[x] - 1;
		long ret = 1;
		for (int i : adj[x])
		{
			ret = (ret * dfs(i)) % 1000000007;
			ret = (ret * c(s, size[i])) % 1000000007;
			s -= size[i];
		}
		return dp[x] = ret % 1000000007;
	}

	static long c(int n, int r)
	{
		long i = p(f[r] * f[n - r], 1000000005) % 1000000007;
		return (f[n] * i) % 1000000007;
	}

	static long p(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % 1000000007) * (x % 1000000007))
			if ((n >> i & 1) != 0)
				a = (a % 1000000007) * (x % 1000000007);
		return a % 1000000007;
	}

	public static void main(String[] args) throws Exception
	{
		int m = readInt();
		adj = new ArrayList[m + 1];
		f = new long[m + 1];
		f[0] = 1;
		for (int i = 0; i <= m; i++)
			adj[i] = new ArrayList<Integer>();

		for (int i = 1; i <= m; i++)
		{
			int x = readInt();
			adj[x].add(i);
			f[i] = (f[i - 1] * i) % 1000000007;
		}

		size = new int[m + 1];
		fillSize(0);

		dp = new long[m + 1];
		System.out.println(dfs(0));
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
