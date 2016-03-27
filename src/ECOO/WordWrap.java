package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class WordWrap
{

	public static void main(String[] args) throws Exception
	{
		for (int i = 0; i < 10; i++)
		{
			int w = readInt();
			String[] words = readLine().split(" ");

			int x = 1;
			for (String s : words)
				if (x + s.length() <= w)
				{
					if (x == 1)
						System.out.print(s);
					else
						System.out.print(" " + s);
					x += s.length();
				}
				else if (x == 1 && s.length() >= w)
				{
					System.out.println(s.substring(0, w + 1));
					System.out.print(s.substring(w + 1));
					x = s.length() - w;
				}
				else
				{
					System.out.println();
					System.out.print(s);
					x += s.length();
				}

			System.out.println("\n=====");
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
