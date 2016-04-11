package ECOO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TheInterlaceCypher
{
	static String encode(String[] words)
	{
		String ret = "";
		int[] pt = new int[words.length];
		int c = -1;
		for (int i = 0; i < words.length; i++)
		{
			for (int j = 0; j < words[i].length(); j++)
			{
				do
					c = (c + 1) % words.length;
				while (pt[c] >= words[c].length());
				ret += words[c].charAt(pt[c]);
				pt[c]++;
			}
			ret += " ";
		}
		
		return ret.trim();
	}

	static String decode(String[] words)
	{
		String[] original = new String[words.length];
		Arrays.fill(original, "");
		int[] pt = new int[words.length];
		int c = -1;
		for (int i = 0; i < words.length; i++)
			for (int j = 0; j < words[i].length(); j++)
			{
				do
					c = (c + 1) % words.length;
				while (pt[c] >= words[c].length());
				original[c] += words[i].charAt(j);
				pt[c]++;
			}
		
		
		String ret = "";
		for (String s : original)
			ret += s + " ";
		return ret.trim();
	}

	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 10; t++)
			if (readLine().equals("encode"))
				System.out.println(encode(readLine().split(" ")));
			else
				System.out.println(decode(readLine().split(" ")));
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
