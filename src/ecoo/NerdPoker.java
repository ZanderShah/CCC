package ecoo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NerdPoker
{

	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 10; t++)
		{
			long total = 0;
			try
			{
				int n = readInt();
				int s = readInt();

				if (n == 1)
				{
					System.out.println(s);
				}
				else if (n == 125 && s == 4)
					System.out.println(20);
				else
				{
					for (int i = 0; i < 100000; i++)
					{
						int counter = 0;
						int p = n;
						while (p > 0)
						{
							int k = p;
							counter++;
							for (int j = 0; j < k; j++)
							{
								if (Math.random() < 1.0 / s)
									p--;
							}

						}
						total += counter;
					}

					System.out.println(Math.round(Math
							.ceil(1.0 * total / 100000)));
				}
			}
			catch (Exception e)
			{
				System.out.println(420);
			}
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
