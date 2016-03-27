package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class fencedin
{
	static int n, m;
	static ArrayList<Path>[] adj;

	static class Path
	{
		int x, d;

		Path(int x, int d)
		{
			this.x = x + 1;
			this.d = d;
		}
	}

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("fencedin.in"));
		PrintWriter out = new PrintWriter(new FileWriter("fencedin.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		int[] v = new int[n + 2];
		for (int i = 1; i <= n; i++)
			v[i] = Integer.parseInt(br.readLine());
		v[n + 1] = a;
		int[] h = new int[m + 2];
		for (int i = 1; i <= m; i++)
			h[i] = Integer.parseInt(br.readLine());
		h[m + 1] = b;

		adj = new ArrayList[(n + 1) * (m + 1)];
		for (int i = 0; i < adj.length; i++)
			adj[i] = new ArrayList<Path>();

		Arrays.sort(v);
		Arrays.sort(h);

		int[] val = new int[n + 1];
		
		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= n; j++)
			{
				int dV = v[j + 1] - v[j];
				int dH = h[i + 1] - h[i];
				int r = i * (n + 1) + j;
				if (i != 0)
					adj[r].add(new Path((i - 1) * (n + 1) + j, dV));
				if (i != m)
					adj[r].add(new Path((i + 1) * (n + 1) + j, dV));
				if (j != 0)
					adj[r].add(new Path(i * (n + 1) + j - 1, dH));
				if (j != n)
					adj[r].add(new Path(i * (n + 1) + j + 1, dH));
			}
		out.println(prims((n + 1) * (m + 1)));
		out.close();
	}

	public static long prims(int n)
	{
		int u = Integer.MAX_VALUE;
		long[] val = new long[n + 1];
		for (int k = 1; k <= n; k++)
			val[k] = -u;
		val[0] = -u - 1;
		int min = 1;
		int k;

		do
		{
			k = min;
			val[k] = -val[k];
			min = 0;
			if (val[k] == u)
				val[k] = 0;

			for (Path t : adj[k - 1])
				if  (val[t.x] < 0)
					if (val[t.x] < -t.d)
						val[t.x] = -t.d;
			for (int t = 1; t <= n; t++)
				if (val[t] < 0)
					if (val[t] > val[min])
						min = t;
		}
		while (min != 0);

		long t = 0;
		for (int i = 1; i <= n; i++)
			t += val[i];
		return t;
	}
}
