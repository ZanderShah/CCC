package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

// Too slow
public class ClassicProblem
{
	static int max(int i, int j)
	{
		if (dpa[i][j] != -1)
			return dpa[i][j];

		if (j - i <= 1)
			return dpa[i][j] = Math.max(val[i], val[j]);
		else
		{
			int max = 0;
			max = Math.max(max, Math.max(max(i, j - 1), max(i + 1, j)));
			return dpa[i][j] = max;
		}
	}

	static int min(int i, int j)
	{
		if (dpb[i][j] != -1)
			return dpb[i][j];

		if (j - i <= 1)
			return dpb[i][j] = Math.min(val[i], val[j]);
		else
		{
			int min = 1 << 30;
			min = Math.min(min, Math.min(min(i, j - 1), min(i + 1, j)));
			return dpb[i][j] = min;
		}
	}

	static int dpa[][], dpb[][], val[];

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int k = readInt();
		dpa = new int[n][n];
		dpb = new int[n][n];
		val = new int[n];

		for (int i = 0; i < n; i++)
		{
			val[i] = readInt();
			Arrays.fill(dpa[i], -1);
			Arrays.fill(dpb[i], -1);
			dpa[i][i] = val[i];
			dpb[i][i] = val[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if (max(i, j) - min(i, j) <= k)
					ans++;
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
