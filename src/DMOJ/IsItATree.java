package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class IsItATree
{
	static void search(int x)
	{
		for (int i = 0; i < 4; i++)
			if (adj[x][i])
			{
				adj[x][i] = false;
				adj[i][x] = false;
				t++;
				search(i);
			}
	}

	static boolean[][] adj;
	static int t = 1, needed = 0;

	public static void main(String[] args) throws Exception
	{
		adj = new boolean[4][4];
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				adj[i][j] = readInt() == 1;
			for (int j = 0; j < 4; j++)
				if (adj[i][j])
				{
					needed++;
					break;
				}
		}

		search(0);

		boolean isTree = true;
		if (t != needed)
			isTree = false;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (adj[i][j])
					isTree = false;

		if (isTree)
			System.out.println("Yes");
		else
			System.out.println("No");
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
