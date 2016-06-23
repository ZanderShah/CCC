package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class RobbersWatch
{
	static boolean valid(String x)
	{
		return Integer.valueOf(x.substring(0, nSize), 7) < n
				&& Integer.valueOf(x.substring(nSize), 7) < m;
	}

	static void combo(String x, int i)
	{
		if (i == nSize + mSize)
		{
			if (valid(x))
				ans++;
		}
		else
		{
			for (int j = 0; j <= 6; j++)
				if (x.indexOf(j + "") == -1)
					combo(x + j, i + 1);
		}
	}

	static int n, m, nSize, mSize, ans = 0;

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		m = readInt();
		nSize = Math.max((int) (Math.log(n - 1) / Math.log(7)) + 1, 1);
		mSize = Math.max((int) (Math.log(m - 1) / Math.log(7)) + 1, 1);

		combo("", 0);
		System.out.println(ans);
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
