package tle;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PrefixSumArray
{
	static long power(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % 1000000007) * (x % 1000000007))
			if ((n >> i & 1) != 0)
				a = (a % 1000000007) * (x % 1000000007);
		return a % 1000000007;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		long[] initial = new long[n + 1];

		for (int i = 1; i <= n; i++)
			initial[i] = readLong();

		long[] answer = new long[n + 1];
		long[] multiplier = new long[n + 1];
		multiplier[0] = 1;

		Long m = readLong() - 1;

		for (int i = 1; i <= n; i++)
			multiplier[i] = (((m + i) * multiplier[i - 1]) % 1000000007 * power(i, 1000000005)) % 1000000007; 

		for (int i = 1; i <= n; i++)
		{
			answer[i] = 0;
			for (int j = i; j >= 1; j--)
				answer[i] = (answer[i] + (initial[j] * multiplier[i - j]) % 1000000007) % 1000000007;
			out.print(answer[i] + " ");
		}
		out.close();
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
}