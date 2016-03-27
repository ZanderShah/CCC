package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Diamonds
{

	public static void main(String[] args) throws Exception
	{
		for (int c = 0; c < 5; c++)
		{
			String s = readLine();
			
			for (int i = 0; i < s.length() - 1; i++)
				System.out.print(" ");
			System.out.println(s.charAt(0));
			
			for (int i = 1; i < s.length(); i++)
			{
				for (int j = 0; j < s.length() - i - 1; j++)
					System.out.print(" ");
				System.out.print(s.charAt(i));
				for (int j = 0; j < 2 * i - 1; j++)
					System.out.print(" ");
				System.out.println(s.charAt(i));
			}
			
			for (int i = s.length() - 2; i > 0; i--)
			{
				for (int j = 0; j < s.length() - 1 - i; j++)
					System.out.print(" ");
				System.out.print(s.charAt(i));
				for (int j = 0; j < 2 * i - 1; j++)
					System.out.print(" ");
				System.out.println(s.charAt(i));
			}
			
			for (int i = 0; i < s.length() - 1; i++)
				System.out.print(" ");
			System.out.println(s.charAt(0));
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
