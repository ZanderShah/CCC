import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ArrivalTime
{

	public static void main(String[] args) throws Exception
	{
		String[] t = readLine().split(":");
		int h = Integer.parseInt(t[0]);
		int m = Integer.parseInt(t[1]);
		m += h * 60;

		if (m <= 5 * 60 || (m >= 10 * 60 && m <= 13 * 60) || m >= 19 * 60)
			m += 2 * 60;
		else
		{
			int n = 120;

			if (m > 13 * 60)
			{
				int d = 15 * 60 - m;
				if (d < 0)
					d = 0;
				m += d;
				n -= d;

				if (m + 2 * n <= 19 * 60)
					m += 2 * n;
				else
				{
					n -= (19 * 60 - m) / 2;
					m += (19 * 60 - m) + n;
				}
			}
			else if (m > 5 * 60)
			{
				int d = 7 * 60 - m;
				if (d < 0)
					d = 0;
				m += d;
				n -= d;

				if (m + 2 * n <= 10 * 60)
					m += 2 * n;
				else
				{
					n -= (10 * 60 - m) / 2;
					m += (10 * 60 - m) + n;
				}
			}
		}

		m %= 24 * 60;
		h = m / 60;
		m %= 60;

		System.out.printf("%02d:%02d", h, m);
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
