package mwc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BreakingIce
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		boolean[][] p = new boolean[10000][10000];
		int x = 5000;
		int y = 5000;
		p[x][y] = true;
		boolean done = false;
		
		for (int i = 1; i <= n && !done; i++)
		{
			char move = readChar();
			if (move == 'U')
				y--;
			else if (move == 'D')
				y++;
			else if (move == 'R')
				x++;
			else if (move == 'L')
				x--;
			
			if (p[y][x])
			{
				System.out.println("Fell at " + i);
				done = true;
			}
			else
				p[y][x] = true;
		}
		
		if (!done)
			System.out.println("Safe!");
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
