package MWC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Symmetry
{

	public static void main(String[] args) throws Exception
	{
		String n = readLine();
		
		ArrayList<String> res = new ArrayList<String>();
		
		String start = "";
		for (int i = 0; i < n.length(); i++)
			for (int j = 0; j <= i; j++)
				start += n.charAt(i);
		for (int i = n.length() - 2; i >= 0; i--)
			for (int j = 0; j <= i; j++)
				start += n.charAt(i);

		for (int i = 0; i <= start.length() / 2; i++)
		{
			String next = "";
			for (int j = 0; j < start.length(); j++)
				if (j <= i || j >= start.length() - i - 1)
					next += start.charAt(0);
				else
					next += start.charAt(j);
			res.add(next);
		}
		
		for (int i = 0; i < res.size(); i++)
			out.println(res.get(i));
		for (int i = res.size() - 2; i >= 0; i--)
			out.println(res.get(i));
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
