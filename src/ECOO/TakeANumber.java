package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TakeANumber
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();

		String s = readLine();
		int l = 0;
		int p = 0;

		while (!s.equals("EOF"))
		{
			if (s.equals("TAKE"))
			{
				n++;
				if (n == 1000)
					n = 1;

				l++;
				p++;
			}
			else if (s.equals("SERVE"))
				l--;
			else if (s.equals("CLOSE"))
			{
				out.printf("%d %d %d\n", p, l, n);
				p = 0;
				l = 0;
			}
			s = readLine();
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
