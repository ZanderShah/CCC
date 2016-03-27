package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class marathon
{
	public static int[] x, y;

	public static int dist(int a, int b)
	{
		return Math.abs(x[a] - x[b]) + Math.abs(y[a] - y[b]);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("marathon.in"));

		PrintWriter out = new PrintWriter(new FileWriter("marathon.out"));

		int n = Integer.parseInt(br.readLine());

		x = new int[n];
		y = new int[n];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			y[i] = Integer.parseInt(st.nextToken());
		}

		int best = -1;
		int dist = 0;

		for (int i = 1; i < n - 1; i++)
			if (dist(i - 1, i) + dist(i, i + 1) > dist(i - 1, i + 1))
				if ((dist(i - 1, i) + dist(i, i + 1)) - dist(i - 1, i + 1) > dist)
				{
					dist = dist(i - 1, i) + dist(i, i + 1) - dist(i - 1, i + 1);
					best = i;
				}

		int total = 0;
		for (int i = 0; i < n - 1; i++)
			if (i != best)
			{
				if (i + 1 == best)
					total += dist(i, i + 2);
				else
					total += dist(i, i + 1);
			}

		out.println(total);
		out.close();
	}
}
