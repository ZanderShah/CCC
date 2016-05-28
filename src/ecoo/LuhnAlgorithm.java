package ecoo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class LuhnAlgorithm
{
	static int generate(String s)
	{
		int r = 0;

		for (int i = s.length() - 1; i >= 0; i--)
			if ((s.length() - 1 - i) % 2 == 1)
				r += (s.charAt(i) - '0') % 10;
			else
			{
				int q = (s.charAt(i) - '0') % 10;
				q *= 2;

				while (q != 0)
				{
					r += q % 10;
					q /= 10;
				}
			}
		return r;
	}

	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 5; t++)
		{
			for (int i = 0; i < 5; i++)
			{
				int d = generate(next());

				for (int g = 0; g < 10; g++)
					if ((d + g) % 10 == 0)
						System.out.print(g);
			}
			System.out.println();
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
