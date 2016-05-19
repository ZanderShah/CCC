package DMOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Pandemic
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), r = readInt(), m = readInt();
		
		HashSet<Integer> rock = new HashSet<Integer>();
		
		for (int i = 0; i < r; i++)
			rock.add(readInt());
		
		int[] pass = new int[m];
		int ro = 0;
		
		for (int i = 0; i < m; i++)
		{
			pass[i] = readInt();
			if (rock.contains(pass[i]))
				ro++;
		}
		
		int norm = m - ro;
		while(norm < ro)
		{
			norm++;
			ro--;
		}
		
		System.out.println(norm * (norm + 1) / 2 + ro * (ro + 1) / 2);
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
