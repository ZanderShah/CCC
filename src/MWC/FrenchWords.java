package MWC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class FrenchWords
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = readInt();
		ArrayList<String> a = new ArrayList<String>(), b = new ArrayList<String>();

		for (int i = 0; i < n; i++)
		{
			String w = next();
			if (a.size() == 0 || !a.get(a.size() - 1).equals(w))
				a.add(w);
		}

		for (int i = 0; i < m; i++)
		{
			String w = next();
			if (b.size() == 0 || !b.get(b.size() - 1).equals(w))
				b.add(w);
		}

		int ans = 0;

		for (int i = 0, j = 0; i < a.size() && j < b.size();)
			if (a.get(i).equals(b.get(j)))
			{
				ans++;
				i++;
			}
			else if (a.get(i).compareTo(b.get(j)) < 0)
				i++;
			else
				j++;

		System.out.println(ans);
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