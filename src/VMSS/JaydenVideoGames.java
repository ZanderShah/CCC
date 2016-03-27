package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class JaydenVideoGames
{
	static int n;
	static Tree[] t;
	static int[] l, r;

	static int right(int x)
	{
		if (x >= n - 1)
			return n;

		int max = r[x];
		for (int i = x + 1; i <= r[x]; i++)
			max = Math.max(max, right(i));

		return max;
	}

	static void fill(int x)
	{
		r[x] = Math.max(right(x), r[x]);
		left(x);
	}

	static void left(int x)
	{
		for (int i = l[x]; i >= 0; i--)
			if (l[i] >= x)
				l[i] = Math.max(l[i], l[x]);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		t = new Tree[n];
		l = new int[n];
		r = new int[n];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			t[i] = new Tree(Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken()));
		}

		Arrays.sort(t);

		for (int i = 0; i < n; i++)
		{
			int d = i;
			while (d + 1 < n && t[i].h >= t[d + 1].x - t[i].x)
				d++;

			for (int j = i; j <= d; j++)
				r[j] = Math.max(r[j], d);

			d = i;
			l[i] = Math.max(l[i], i);
			while (d > 0 && t[i].x - t[i].h <= t[d - 1].x)
			{
				d--;
				l[d] = Math.max(l[i], l[d]);
			}
		}

		for (int i = n - 1; i >= 0; i--)
			fill(i);

		int i = 0;
		int min = 0;
		while (i < n)
		{
			min++;
			i = Math.max(l[i], r[i]) + 1;
		}

		System.out.println(min);
	}

	static class Tree implements Comparable<Tree>
	{
		int x;
		int h;

		Tree(int x, int h)
		{
			this.x = x;
			this.h = h;
		}

		public int compareTo(Tree t)
		{
			return this.x - t.x;
		}
	}
}