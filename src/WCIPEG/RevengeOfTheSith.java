package WCIPEG;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class RevengeOfTheSith
{
	public static int n, m, r, b;
	public static int[] c = new int[45678];
	public static Room[] rooms = new Room[45678];
	public static boolean distinct;

	public static void colour(int i, int t)
	{
		for (Integer j : rooms[i].path)
			if (c[j] == 0)
				if (t == 1)
				{
					c[j] = 2;
					b++;
					colour(j, 2);
				}
				else
				{
					c[j] = 1;
					r++;
					colour(j, 1);
				}
			else if (c[j] == t)
				distinct = false;
	}

	public static class Room
	{
		ArrayList<Integer> path = new ArrayList<Integer>();

		public Room()
		{

		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < 45678; i++)
			rooms[i] = new Room();

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			rooms[a].path.add(b);
			rooms[b].path.add(a);
		}

		int p = 0;

		for (int i = 0; i < n; i++)
			if (c[i] == 0)
			{
				distinct = true;
				r = 0;
				b = 0;
				colour(i, 1);
				if (distinct)
					p += r * r + b * b;
				else
					p += (r + b) * (r + b);

			}

		System.out.println(p * 1.0 / (n * n));
	}

}
