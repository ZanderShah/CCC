package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BinaryIndexedTreeTest
{
	static int less[];
	static long sum[];

	static void pointUpdate(int x, long v)
	{
		for (; x <= 100000; x += (x & (-x)))
			sum[x] += v;
	}

	static void rangeUpdate(int l, int r)
	{
		while (l <= 100000 || r <= 100000)
		{
			if (l <= 100000)
			{
				less[l]--;
				l += (l & (-l));
			}
			if (r <= 100000)
			{
				less[r]++;
				r += (r & (-r));
			}
		}
	}

	static long rangeQuery(int l, int r)
	{
		long ans = 0;
		while (l > 0 || r > 0)
		{
			if (l > 0)
			{
				ans -= sum[l];
				l -= (l & (-l));
			}
			if (r > 0)
			{
				ans += sum[r];
				r -= (r & (-r));
			}
		}

		return ans;
	}

	static int pointQuery(int x)
	{
		int ans = 0;
		for (; x > 0; x -= (x & (-x)))
			ans += less[x];
		return ans;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(
				System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		sum = new long[100001];
		int[] val = new int[100001];
		less = new int[100001];
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++)
		{
			val[i] = Integer.parseInt(st.nextToken());
			int k = i;
			int r = val[i];

			while (k <= 100000 || r <= 100000)
			{
				if (k <= 100000)
				{
					sum[k] += val[i];
					k += (k & (-k));
				}
				if (r <= 100000)
				{
					less[r]++;
					r += (r & (-r));
				}
			}
		}

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			char c = st.nextToken().charAt(0);

			if (c == 'C')
			{
				int x = Integer.parseInt(st.nextToken());
				int v = Integer.parseInt(st.nextToken());
				pointUpdate(x, v - val[x]);
				rangeUpdate(val[x], v);
				val[x] = v;
			}
			else if (c == 'S')
				out.println(rangeQuery(
						Integer.parseInt(st.nextToken()) - 1,
						Integer.parseInt(st.nextToken())));
			else
			{
				int v = Integer.parseInt(st.nextToken());
				out.println(pointQuery(v));
			}
		}
		out.close();
	}
}
