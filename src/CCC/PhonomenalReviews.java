package CCC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 * Alexander Shah
 * Richmond Hill High School 
 * 073832644
 * Senior
 * S3
 */
public class PhonomenalReviews
{
	static boolean trim(int node, int distance)
	{
		if (distance > max && pho[node])
		{
			start = node;
			max = distance;
		}
		for (int newNode : adj[node])
			if (!vis[newNode])
			{
				vis[newNode] = true;
				if (trim(newNode, distance + 1))
					pho[node] = true;
			}

		return pho[node];
	}
	
	static int all(int node, int distance)
	{
		if (distance > max)
			max = distance;
		int total = 0;
		for (int newNode : adj[node])
			if (!vis[newNode] && pho[newNode])
			{
				vis[newNode] = true;
				total += all(newNode, distance + 1) + 1;
			}
		
		return total;
	}
	
	static ArrayList<Integer>[] adj;
	static int n, m, start, max = 0;
	static boolean[] pho;
	static boolean[] vis;

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		for (int node = 0; node < n; node++)
			adj[node] = new ArrayList<Integer>();

		pho = new boolean[n];

		st = new StringTokenizer(br.readLine());
		start = 0;
		for (int destinations = 0; destinations < m; destinations++)
		{
			int p = Integer.parseInt(st.nextToken());
			if (destinations == 0)
				start = p;
			pho[p] = true;
		}

		for (int path = 0; path < n - 1; path++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			adj[a].add(b);
			adj[b].add(a);
		}

		vis = new boolean[n];
		vis[start] = true;
		trim(start, 0);
		
		vis = new boolean[n];
		vis[start] = true;
		out.println(all(start, 0) * 2 - max);
		out.close();
	}

}