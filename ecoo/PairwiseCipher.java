package ecoo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class PairwiseCipher
{
	static char neighbour(boolean left, char c)
	{
		if (left)
			return key.charAt((key.indexOf(c) + 25) % 26);
		else
			return key.charAt((key.indexOf(c) + 1) % 26);
	}

	static String key;

	public static void main(String[] args) throws Exception
	{
		for (int c = 0; c < 5; c++)
		{
			String m = readLine().toUpperCase();
			String e = readLine().toUpperCase();

			key = "";
			boolean[] l = new boolean[26];

			for (int i = 0; i < m.length(); i++)
				if (Character.isLetter(m.charAt(i)))
					if (!l[m.charAt(i) - 'A'])
					{
						key += m.charAt(i);
						l[m.charAt(i) - 'A'] = true;
					}

			for (int i = 0; i < 26; i++)
				if (!l[i])
					key += (char) (i + 'A');

			System.out.println(key);

			String o = "";
			for (int i = 0; i < e.length(); i += 2)
			{
				char a = neighbour(true, e.charAt(i));
				char b = neighbour(false, e.charAt(i + 1));
				o += b;
				o += a;
			}
			
			o = o.replace('X', ' ');
			o = o.replace("KS", "X");

			System.out.println(o);
		}
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
