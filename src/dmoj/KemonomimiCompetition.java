package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class KemonomimiCompetition
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int[] c = { readInt(), readInt(), readInt(), readInt() };
		int[][] q = new int[n][4];
		int w = 0;

		for (int i = 0; i < n; i++)
		{
			q[i][0] = readInt() - 1;
			q[i][1] = readInt();
			q[i][2] = readInt();
			q[i][3] = readInt();
			w = Math.max(q[i][2], w);
		}
		w = 180 - w;
		for (int i = 0; i < n; i++)
			if (q[i][1] == 10)
				System.out.println("0");
			else if (q[i][3] * c[q[i][0]] <= w)
				System.out.println(10 - q[i][1]);
			else
				System.out.println("The kemonomimi are too cute!");
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
