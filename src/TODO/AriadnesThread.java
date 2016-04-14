package TODO;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class AriadnesThread
{
	static int n, dist[], d = 0, u, v;
	static ArrayList<Integer>[] adj;
	static HashMap<Integer, Integer> find = new HashMap<Integer, Integer>();

	static void fill(int x)
	{
		dist[x] = d;
		find.put(x, d);
		for (Integer i : adj[x])
		{
			d++;
			fill(i);
		}
		d++;
		
	}

	public static void main(String[] args) throws Exception
	{
		n = readInt();
		dist = new int[n];
		adj = new ArrayList[n];
		HashSet<Integer>[] parents = new HashSet[n];
		int[] parent = new int[n];

		for (int i = 0; i < n; i++)
		{
			adj[i] = new ArrayList<Integer>();
			parents[i] = new HashSet<Integer>();
			dist[i] = -1;
			int c = readInt();
			for (int j = 0, x; j < c; j++)
			{
				x = readInt() - 1;
				parent[x] = i;
				adj[i].add(x);
			}
		}

		fill(0);

		int q = readInt();
		for (int i = 0; i < q; i++)
		{
			u = readInt() - 1;
			v = readInt() - 1;
			
			if (find.get(u).compareTo(find.get(v)) < 0)
			{
				if (parents[v].size() == 0)
				{
					int x = v;
					while(parent[x] != 0)
					{
						parents[v].add(x);
						x = parent[x];
					}
					parents[v].add(0);
				}
				
				d = 0;
				while (!parents[v].contains(u))
				{
					u = parent[u];
					d++;
				}
				
				System.out.println(dist[v] - dist[u] - d);
			}
			else
			{
				System.out.println("idk");
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
