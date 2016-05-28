package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class KittansDilemma
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int m = readInt();
		ArrayList<Long> bad = new ArrayList<Long>();
		ArrayList<Long> good = new ArrayList<Long>();

		for (int i = 0; i < n; i++)
		{
			long s = readLong();
			if (readInt() == 1)
				bad.add(s);
			else
				good.add(s);
		}

		Collections.sort(bad);
		Collections.sort(good);
		long[] bady = new long[bad.size() + 1];
		long[] goody = new long[good.size() + 1];

		for (int i = 1; i <= bad.size(); i++)
			bady[i] = bady[i - 1] + bad.get(i - 1);

		int maxp = 0;

		for (int i = 0, x; i <= good.size(); i++)
		{
			if (i != 0)
				goody[i] = goody[i - 1] + good.get(i - 1);

			if (goody[i] <= m)
			{
				x = Math.min(bad.size(),
						Math.abs(Arrays.binarySearch(bady, m - goody[i]) + 2));
				while (x >= 1 && bady[x] > m - goody[i])
					x--;

				maxp = Math.max(x + 2 * i, maxp);
			}
		}

		System.out.println(maxp);
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
