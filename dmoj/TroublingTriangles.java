package dmoj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TroublingTriangles
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt();

		for (int i = 0; i < n; i++)
		{
			double a = readDouble(), b = readDouble(), c = readDouble(), d = readDouble(), e = readDouble(), f = readDouble();
			// Cross product ish?
			System.out.printf("%f %f%n",
					Math.abs((c - a) * (f - b) - (e - a) * (d - b)) / 2,
					Math.sqrt((a - c) * (a - c) + (b - d) * (b - d))
							+ Math.sqrt((a - e) * (a - e) + (b - f) * (b - f))
							+ Math.sqrt((c - e) * (c - e) + (d - f) * (d - f)));
		}
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}
}
