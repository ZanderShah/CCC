package tle;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class OlympiadsHomework
{
	static long power(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 64; i++, x = (x % 1000000013) * (x % 1000000013))
			if ((n >> i & 1) != 0)
				a = (a % 1000000013) * (x % 1000000013);
		return a % 1000000013;
	}

	public static void main(String[] args) throws Exception
	{
		long i = readLong();

		if (i == 1)
			System.out.println(1);
		else if (i % 8 == 0 || i % 8 == 1 || i % 8 == 7)
			System.out.println((power(2, i - 2)
					+ power(2, i / 2 - 1)) % 1000000013);
		else if (i % 8 == 2 || i % 8 == 6)
			System.out.println(power(2, i - 2));
		else
			System.out.println((power(2, i - 2)
					- power(2, i / 2 - 1) + 1000000013) % 1000000013);
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
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

}
