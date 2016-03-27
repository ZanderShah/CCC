package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class TotalAnnihilation
{
	static long[] o, p;
	static HashMap<Long, Integer> c = new HashMap<Long, Integer>();
	static long count;

	static void solve1(int i, long sum, boolean t)
	{
		if (t)
			if (sum == 0)
				count++;
			else if (c.containsKey(sum))
			{
				int v = c.get(sum) + 1;
				c.remove(sum);
				c.put(sum, v);
			}
			else
				c.put(sum, 1);

		if (i != o.length)
		{
			solve1(i + 1, sum, false);
			solve1(i + 1, sum + o[i], true);
		}
	}

	static void solve2(int i, long sum, boolean t)
	{
		if (t)
			if (sum == 0)
				count++;
			else if (c.containsKey(-sum))
				count += c.get(-sum);

		if (i != p.length)
		{
			solve2(i + 1, sum, false);
			solve2(i + 1, sum + p[i], true);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		long[] s = new long[n + m];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			s[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < m; i++)
			s[i + n] = -Integer.parseInt(st.nextToken());

		o = new long[(n + m) / 2];
		p = new long[n + m - o.length];
		for (int i = 0; i < n + m; i++)
		{
			if (i < o.length)
				o[i] = s[i];
			else
				p[i - o.length] = s[i];
		}

		solve1(0, 0, false);
		solve2(0, 0, false);
		System.out.println(count);
	}

}
