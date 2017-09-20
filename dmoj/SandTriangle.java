package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SandTriangle
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();

		long l = 1;
		long u = 1000000000;
		long p = (l + u) / 2;

		while (true)
		{
			if ((p * (p + 1)) / 2 < n)
				l = (l + u) / 2;
			else
				u = (l + u) / 2;
			
			if (p == (l + u) / 2)
				break;
			
			p = (l + u) / 2;
		}
		
		while (p * (p + 1) / 2 >= n)
			p--;
		while ((p + 1) * (p + 2) / 2 < n)
			p++;
		
		
		long a = p * (p + 1) / 2 + 1;
		long b = (p + 1) * (p + 2) / 2;
		
		System.out.println((long)(((a + b) * 1.0 / 2) * (b - a + 1)));
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
