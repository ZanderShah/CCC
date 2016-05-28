package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class AdminWar2
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int[] a = new int[n], b = new int[n];
		
		for (int i = 0; i < n; i++)
			a[i] = readInt();
		for (int i = 0; i < n; i++)
			b[i] = readInt();

		Arrays.sort(a);
		Arrays.sort(b);

		int j = 0;
		for (int i = 0; i < n; i++)
			if (a[i] > b[j])
				j++;
		System.out.println(j);
		j = 0;
		for (int i = 0; i < n; i++)
			if (b[i] > a[j])
				j++;
		System.out.println(j);
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
