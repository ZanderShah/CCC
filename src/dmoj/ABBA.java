package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ABBA
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();

		for (int r = 0; r < n; r++)
		{
			String s = readLine(), t = readLine();

			while (t.length() != s.length())
			{
				if (t.charAt(t.length() - 1) == 'A')
					t = t.substring(0, t.length() - 1);
				else
				{
					String e = "";

					for (int i = t.length() - 2; i >= 0; i--)
						e += t.charAt(i);

					t = e;
				}
			}

			System.out.println((t.equals(s) ? "YES" : "NO"));
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
