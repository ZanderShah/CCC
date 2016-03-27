package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class OriginOfLife
{
	static int m, n, goal, min;
	static int[] state;

	static int neighbours(int x, int y, int s)
	{
		int neighbours = 0;
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
				if (i >= 0 && j >= 0 && i < m && j < n && (i != x || j != y)
						&& ((s & 1 << i * n + j) != 0))
					neighbours++;

		return neighbours;
	}

	static int works(int x, int d)
	{
		if (d < min && d < 50)
		{
			if (x == goal)
				return d;

			return works(state[x], d + 1);
		}
		else
			return Integer.MAX_VALUE;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());

		goal = 0;
		int pow = 1;
		for (int i = 0; i < m; i++)
		{
			String temp = br.readLine();
			for (int j = 0; j < n; j++)
			{
				if (temp.charAt(j) == '*')
					goal += pow;
				pow *= 2;
			}
		}
		pow *= 2;

		state = new int[pow];
		for (int i = 0; i < pow; i++)
			state[i] = i;
		boolean[] isEden = new boolean[pow];
		Arrays.fill(isEden, true);
		
		for (int q = 0; q < pow; q++)
		{
			int newState = state[q];

			pow = 1;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					int live = neighbours(i, j, state[q]);
					if (((state[q] & (1 << i * n + j)) != 0) && (live < a || live > b))
						newState -= pow;
					else if (((state[q] & (1 << i * n + j)) == 0) && live > c)
						newState += pow;

					pow *= 2;
				}
			pow *= 2;

			state[q] = newState;
			isEden[state[q]] = false;
		}

		min = Integer.MAX_VALUE;
		for (int i = 0; i < pow; i++)
			if (isEden[i])
			{
				int t = works(i, 0);
				if (t < min)
					min = t;
			}

		if (min == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(min);
	}
}
