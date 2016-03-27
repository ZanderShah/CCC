package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class SerialNumberDates
{

	public static void main(String[] args) throws Exception
	{
		for (int c = 0; c < 5; c++)
		{
			String[] date = readLine().split(".");

			long days = Integer.parseInt(date[0]);
			double partOfDay = Integer.parseInt(date[1])
					/ Math.pow(10, date[1].length());

			long extra = days / 365;
			long leap = extra / 4 + 1;
			long year = 1904 + extra;
			days -= extra * 365 + leap;

			int[] dOfM = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

			int month = 0;
			for (; month < 12; month++)
				if (month == 1 && year % 4 == 0 && days > 29)
					days -= 29;
				else if (days > dOfM[month])
					days -= dOfM[month];
				else
					break;

			int hour = 0;
			for (; hour < 24; hour++)
				if (1.0 / 60 < partOfDay)
					partOfDay -= 1.0 / 60;
				else
				{
					hour--;
					break;
				}
			
			System.out.println(year + " " + month + " " + hour);
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
