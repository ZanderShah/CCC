package TSOC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MaryJaneAndInvitations
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		char[] type = new char[n];
		String s = readLine();

		for (int i = 0, t = 0; i < s.length(); i++, t++)
			if (s.charAt(i) != 'X')
				type[t] = s.charAt(i);
			else
			{
				int c = 0;
				for (; i < s.length() && s.charAt(i) == 'X'; i++)
					c++;

				type[t - c] = s.charAt(i);
				t--;
			}

		for (int i = 0; i < n; i++)
			if (type[i] == 'A')
				System.out
						.printf("Dear %s, beloved artist, I would love to have you at my party. Come to my crib on April 20th.\n",
								readLine());
			else if (type[i] == 'O')
				System.out
						.printf("Dear %s, beloved occasion enthusiast, come to my crib to celebrate this very special day.\n",
								readLine());
			else
				System.out
						.printf("Dear %s, April 20th is happening again this year. Don't miss out.\n",
								readLine());
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
