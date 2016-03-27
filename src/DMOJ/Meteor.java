package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Meteor
{

	public static void main(String[] args) throws Exception
	{
		int r = readInt();
		int s = readInt();
		char[][] m = new char[r][s];
		int[] low = new int[s];
		Arrays.fill(low, -1);

		for (int i = 0; i < r; i++)
		{
			String l = readLine();
			for (int j = 0; j < s; j++)
			{
				m[i][j] = l.charAt(j);
				if (m[i][j] == 'X')
					low[j] = i;
			}
		}

		int[] d = new int[s];
		for (int i = 0; i < s; i++)
			if (low[i] != -1)
				for (int j = low[i] + 1; j < r; j++)
					if (m[j][i] == '.')
						d[i]++;
					else
						break;

		int min = Integer.MAX_VALUE;
		for (int i = 0; i < s; i++)
			if (low[i] != -1)
				min = Math.min(min, d[i]);

		for (int i = r - 1; i >= 0; i--)
			for (int j = 0; j < s; j++)
				if (m[i][j] == 'X')
					m[i + min][j] = '*';

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < s; j++)
			{
				if (m[i][j] == '*')
					out.print('X');
				else if (m[i][j] == 'X')
					out.print('.');
				else
					out.print(m[i][j]);
			}
			out.println();
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
