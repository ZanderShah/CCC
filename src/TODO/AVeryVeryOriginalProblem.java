package TODO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class AVeryVeryOriginalProblem
{
	static boolean isPalindrome(int l, int r)
	{
		for (; l <= r; l++, r--)
			if (s.charAt(l) != s.charAt(r))
				return false;
		return true;
	}

	static String s;

	public static void main(String[] args) throws Exception
	{
		s = readLine();
		int n = s.length();

		TreeMap<Integer, Integer> findRight = new TreeMap<Integer, Integer>();
		TreeMap<Integer, Integer> findLeft = new TreeMap<Integer, Integer>();
		
		long ans = 0;

		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				if (isPalindrome(i, j))
				{
					if (findRight.get(i) != null)
						ans += findRight.get(i);
					if (findLeft.get(j) != null)
						ans += findLeft.get(j);
					findRight.put(j, j);
					findRight.put(i, i);
				}

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
