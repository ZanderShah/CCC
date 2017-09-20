package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class GeneticProbability
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		String a = readLine();
		String b = readLine();
		String c = readLine();
		
		double ans = 1;
		
		for (int i = 0; i < 2 * n; i += 2)
		{
			char p = c.charAt(i);
			char q = c.charAt(i + 1);
			
			double sub = 0;
			
			if ((a.charAt(i) == p && b.charAt(i) == q) || (a.charAt(i) == q && b.charAt(i) == p))
				sub += 0.25;
			if ((a.charAt(i) == p && b.charAt(i + 1) == q) || (a.charAt(i) == q && b.charAt(i + 1) == p))
				sub += 0.25;
			if ((a.charAt(i + 1) == p && b.charAt(i) == q) || (a.charAt(i + 1) == q && b.charAt(i) == p))
				sub += 0.25;
			if ((a.charAt(i + 1) == p && b.charAt(i + 1) == q) || (a.charAt(i + 1) == q && b.charAt(i + 1) == p))
				sub += 0.25;
			
			ans *= sub;
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
