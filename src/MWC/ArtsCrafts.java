package MWC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class ArtsCrafts
{
	public static void main(String[] args) throws Exception
	{
		int n = readInt(), x = readInt(), y = readInt();

		TreeSet<Integer> v = new TreeSet<Integer>();
		v.add(x);
		TreeMap<Integer, Integer> h = new TreeMap<Integer, Integer>();

		for (int i = 0; i < n; i++)
		{
			char c = readChar();

			if (c == 'h')
			{
				int s = readInt(), d = readInt();
				if (h.containsKey(s) && h.get(s) < d)
					h.replace(s, d);
				else if (!h.containsKey(s))
					h.put(s, d);
			}
			else
				v.add(readInt());
		}

		int t = v.size();
		Iterator<Integer> i = h.navigableKeySet().iterator();
		Integer[] search = v.toArray(new Integer[0]);

		while (i.hasNext())
			t += Math.abs(Arrays.binarySearch(search, h.get(i.next())) + 1);

		System.out.println(t);
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
