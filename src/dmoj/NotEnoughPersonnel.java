package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NotEnoughPersonnel
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		String[] t = new String[n];
		int[] s = new int[n];
		for (int i = 0; i < n; i++)
		{
			t[i] = next();
			s[i] = readInt();
		}
		
		int q = readInt();
		for (int i = 0; i < q; i++)
		{
			int x = readInt(), d = readInt(), a = -1;
			for (int j = 0; j < n; j++)
				if ((s[j] - d <= x && s[j] >= x) && (a == -1 || s[j] < s[a]))
					a = j;
			if (a == -1)
				System.out.println("No suitable teacher!");
			else
				System.out.println(t[a]);
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
