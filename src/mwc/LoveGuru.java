package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class LoveGuru
{
	static long power(long x, long n)
	{
		long a = 1;
		for (int i = 0; i < 21; i++, x = (x % 10) * (x % 10), n >>= 1)
			if ((n & 1) != 0)
				a = (a % 10) * (x % 10);
		return a % 10;
	}

	public static void main(String[] args) throws Exception
	{
		String a = readLine().toLowerCase();
		String b = readLine().toLowerCase();
		
		int[][] ans = new int[1000001][10];
		for (int i = 0; i < 10; i++)
		{
			ans[0][i] = 1;
			ans[1][i] = i;
		}
		
		for (int i = 2; i < 1000001; i++)
			for (int j = 0; j < 10; j++)
				ans[i][j] = (ans[i - 1][j] * ans[1][j]) % 10;

		long ansa = 0, ansb = 0;
		for (int i = 0; i < a.length(); i++)
			ansa = ((ansa + ans[i + 1][(a.charAt(i) - 'a' + 1) % 10]) % 10);
		
		for (int i = 0; i < b.length(); i++)
			ansb = ((ansb + ans[i + 1][(b.charAt(i) - 'a' + 1) % 10]) % 10);

		if (ansa == 0)
			ansa = 10;
		if (ansb == 0)
			ansb = 10;

		System.out.println(ansa + ansb);
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
