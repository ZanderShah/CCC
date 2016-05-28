package wcipeg;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class EnergyAbsorption
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int m = readInt();

		ArrayList<Integer> sum = new ArrayList<Integer>();
		sum.add(0);
		ArrayList<Integer> punch = new ArrayList<Integer>();
		punch.add(0);

		int total = 0;
		for (int i = 1; i <= n; i++)
		{
			total += readInt();

			if (-total > sum.get(sum.size() - 1))
			{
				sum.add(-total);
				punch.add(i);
			}
		}

		for (int q = 0; q < m; q++)
		{
			int ans = Math.abs(Collections.binarySearch(sum, readInt()) + 1);

			if (ans == 0)
				out.println(0);
			else if (ans == sum.size())
				out.println(n);
			else
				out.println(punch.get(ans) - 1);
		}
		out.close();
	}

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

	static char readCharacter() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
