package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ApplesToOranges
{
	static int n, m, start;
	static ArrayList<Rate>[] adj;
	static boolean infinite = false;
	static double[] best;

	static void convert(int x, double v)
	{
		if (!infinite)
			if (x == start && v >= 2)
				infinite = true;
			else if (best[x] < v)
			{
				best[x] = v;
				for (Rate i : adj[x])
					convert(i.r, v * i.c);
			}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		adj = new ArrayList[n];
		best = new double[n];
		for (int i = 0; i < n; i++)
			adj[i] = new ArrayList<Rate>();

		HashMap<String, Integer> fruit = new HashMap<String, Integer>();
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++)
		{
			String f = br.readLine();
			if (f.equals("APPLES"))
				start = i;
			fruit.put(f, i);
		}

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			adj[fruit.get(st.nextToken())].add(new Rate(fruit.get(st
					.nextToken()), Double.parseDouble(st.nextToken())));
		}

		convert(start, 1.0);

		if (infinite)
			System.out.println("YA");
		else
			System.out.println("NAW");
	}

	static class Rate
	{
		int r;
		double c;

		Rate(int r, double c)
		{
			this.r = r;
			this.c = c;
		}
	}
}
