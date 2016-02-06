import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Friends
{
	public static Person[] people;

	public static class Person
	{
		ArrayList<Integer> friends = new ArrayList<Integer>();
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		people = new Person[10000];

		for (int i = 0; i < 10000; i++)
			people[i] = new Person();

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			people[a - 1].friends.add(b - 1);
		}

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		// Preform a bfs on the graph to determine the distance of a friend
		while (a != 0 || b != 0)
		{
			Queue<Integer[]> q = new LinkedList<Integer[]>();
			LinkedList<Integer> vis = new LinkedList<Integer>();
			String s = "";
			q.add(new Integer[] { a - 1, -1 });

			while (!q.isEmpty())
			{
				Integer[] cur = q.poll();
				vis.add(cur[0]);

				if (cur[0].equals(b - 1))
				{
					s += "Yes " + cur[1];
					break;
				}

				for (Integer i : people[cur[0]].friends)
				{
					if (!vis.contains(i))
						q.add(new Integer[] { i, cur[1] + 1 });
				}
			}
			
			if (s.length() == 0)
				System.out.println("No");
			else
				System.out.println(s);
			
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
		}
	}
}
