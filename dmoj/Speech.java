package dmoj;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Speech
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		HashMap<String, String> replace = new HashMap<String, String>();
		for (int i = 0; i < n; i++)
		{
			String a = next().toLowerCase();
			String b = next().toLowerCase();
			replace.put(b, a);
		}

		String[] words = readLine().split(" ");
		for (int i = 0; i < words.length; i++)
		{
			if (words[i].charAt(words[i].length() - 1) == '.')
				words[i] = words[i].substring(0, words[i].length() - 1);
			if (replace.containsKey(words[i]))
				System.out.print(replace.get(words[i]));
			else
				System.out.print(words[i]);
			if (i + 1 != words.length)
				System.out.print(" ");
		}
		
		System.out.print(".");
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
