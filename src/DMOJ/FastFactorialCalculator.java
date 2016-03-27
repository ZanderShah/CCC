package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FastFactorialCalculator
{
	static long f(long x)
	{
		// Will have 2 multiplied in 32 times
		if (x >= 34)
			return 0;

		long ans = 1;
		for (long i = 2; i <= x; i++)
			ans = ((ans % (1l << 32)) * (i % (1l << 32))) % (1l << 32);
		return ans;
	}

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		for (int i = 0; i < n; i++)
		{
			String l = readLine();
			
			// Reading in big numbers hurts me
			if (l.length() >= 3)
				System.out.println(0);
			else
				System.out.println(f(Long.parseLong(l)));
		}
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
