package tsoc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class OhMy
{
	static void go(int a, int x)
	{
		if (x == n)
			verify(a);
		else
		{
			go(a + (1 << x), x + 1);
			go(a, x + 1);
		}
	}

	static void verify(int q)
	{
		char cur;
		char last = 'y';
		
		int a = 0, l = 0;
		for (int i = 0; i < n; i++)
			if ((q & (1 << i)) != 0)
			{
				if (a == 0 && s.charAt(i) != 'o')
					return;
				
				a++;
				cur = s.charAt(i);
				
				if (cur != last)
				{
					if ((cur == 'o' && last != 'y') || (cur == 'h' && last != 'o')
							|| (cur == 'm' && last != 'h') || (cur == 'y'
							&& last != 'm'))
						return;
					last = cur;
					if (last == 'y')
						l++;
				}
			}
		
		if (last != 'y')
			return;

		if (l > h)
		{
			h = l;
			y = s.length() - a;
		}
		else if (l == h)
			y = Math.min(y, s.length() - a);
	}

	static String s;
	static int n;
	static int h = 0, y = 25;

	public static void main(String[] args) throws Exception
	{
		//ohhmyyyyyyyy
		n = readInt();
		s = readLine();

		go(0, 0);
		System.out.print("o");
		for (int i = 0; i < h; i++)
			System.out.print("h");
		System.out.print("m");
		for (int i = 0; i < y; i++)
			System.out.print("y");
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
