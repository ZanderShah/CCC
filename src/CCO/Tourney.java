package CCO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Tourney
{
	static int n, t[];
	static HashMap<Integer, Integer> lookUp;

	static void update(int x, int v)
	{
		lookUp.remove(t[(1 << n) + x]);
		lookUp.put(v, x);
		for (t[x += (1 << n)] = v; x > 1; x >>= 1)
			t[x >> 1] = Math.max(t[x], t[x ^ 1]);
	}

	static int wins(int x)
	{
		int w = -1;
		int s = t[x + (1 << n)];

		for (x += (1 << n); x >= 1 && t[x] == s; x >>= 1)
			w++;

		return w;
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		int m = readInt();
		t = new int[2 * (1 << n)];

		lookUp = new HashMap<Integer, Integer>();

		for (int i = 0; i < 1 << n; i++)
		{
			t[t.length / 2 + i] = readInt();
			lookUp.put(t[t.length / 2 + i], i);
		}
		for (int i = (1 << n) - 1; i > 0; i--)
			t[i] = Math.max(t[i << 1], t[i << 1 | 1]);

		for (int i = 0; i < m; i++)
		{
			char c = readChar();
			if (c == 'W')
			{
				int w = lookUp.get(t[1]) + 1;
				out.println(w);
			}
			else if (c == 'R')
				update(readInt() - 1, readInt());
			else
				out.println(wins(readInt() - 1));
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
