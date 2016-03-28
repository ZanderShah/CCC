package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

// Too slow
public class GrafZeppelin
{

	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int m = readInt();
		int k = readInt();

		ArrayList<Integer>[] adj = new ArrayList[n];
		int[][] dist = new int[n][n];
		boolean[] vis = new boolean[n];
		for (int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
			for (int j = 0; j < n; j++)
				if (i != j)
					dist[i][j] = 1501;
		}

		for (int i = 0, a, b; i < m; i++)
		{
			a = readInt() - 1;
			b = readInt() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		
		for (int i = 0, u, b; i < n; i++)
		{
			while (true)
			{
				u = -1;
				b = 1501;
				
				for (int j = 0; j < n; j++)
					if (!vis[j] && dist[i][j] < b)
					{
						u = j;
						b = dist[i][j];
					}
				
				if (b > 5)
					break;
				
				for (int j : adj[u])
					if (!vis[j])
						dist[i][j] = Math.min(dist[i][j], dist[i][u] + 1);
				
				vis[u] = true;
			}
			
			for (int j = 0; j < n; j++)
				dist[j][i] = dist[i][j];
			
			vis = new boolean[n];
		}

		for (int i = 0; i < n; i++)
		{
			int ans = 0;
			for (int j = 0; j < n; j++)
				if (dist[i][j] <= k)
					ans++;
			System.out.println(ans);
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