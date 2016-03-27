package TLE;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Microwave
{
	static class Time implements Comparable<Time>
	{
		int t, f;
		public Time(int tt, int ff)
		{
			t = tt;
			f = ff;
		}
		
		public int compareTo(Time p)
		{
			return t - p.t;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int x = readInt();
		int t = readInt();
		
		Time[] p = new Time[x];
		for (int i = 0; i < x; i++)
			p[i] = new Time(readInt(), readInt());
		Arrays.sort(p);
		
		int[] m = new int[n];
		int time = p[0].t;
		
		int ans = -1;
		if (time - t >= 0)
			ans = 0;
		
		Queue<Time> q = new LinkedList<Time>();
		
		for (int i = 0; i < x; i++)
		{
			q.add(p[i]);
			for (int j = 0; j < n; j++)
				if (m[j] <= time)
				{
					m[j] = q.peek().f + time;
					q.poll();
				}
			
			
					
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
