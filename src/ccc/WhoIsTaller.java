package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class WhoIsTaller
{
	static Student[] students;
	public static int n;

	private static class Student
	{
		ArrayList<Integer> heights = new ArrayList<Integer>();
	}

	public static boolean solve(int a, int b)
	{
		boolean[] vis = new boolean[n];

		Queue<Integer> q = new LinkedList<Integer>();

		q.add(a);

		while (!q.isEmpty())
		{
			int t = q.poll();

			if (t == b)
				return true;
			
			if (!vis[t])
			{
				vis[t] = true;

				for (int i = 0; i < students[t].heights.size(); i++)
						q.add(students[t].heights.get(i));
			}
		}

		return false;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		students = new Student[n];
		for (int i = 0; i < n; i++)
			students[i] = new Student();
		
		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken()) - 1;
			int q = Integer.parseInt(st.nextToken()) - 1;

			students[p].heights.add(q);
		}

		st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken()) - 1;
		int b = Integer.parseInt(st.nextToken()) - 1;

		// Performs 2 dfs to see who is taller
		if (solve(a, b))
			System.out.println("yes");
		else if (solve(b, a))
			System.out.println("no");
		else
			System.out.println("unknown");
	}
}
