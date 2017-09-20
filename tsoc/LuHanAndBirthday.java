package tsoc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class LuHanAndBirthday
{
	static boolean isPrime(int x)
	{
		for (int i = 2; i * i <= x; i++)
			if (x % i == 0)
				return false;
		return true;
	}

	public static void main(String[] args) throws Exception
	{
		int a = readInt(), b = readInt(), c = readInt(), d = readInt();

		ArrayList<Integer> p = new ArrayList<Integer>();
		for (; a <= b; a++)
			if (isPrime(a))
				p.add(a);
		long sum = 0;

		for (int x : p)
			for (int i = 1; x * i <= d; i++)
				if (x * i >= c)
					sum += x * i;

		System.out.println(sum % 2016420);
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
