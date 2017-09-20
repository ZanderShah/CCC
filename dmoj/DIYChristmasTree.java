package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class DIYChristmasTree
{
	public static Node[] nodes;
	public static int[] fam;

	public static class Node
	{
		ArrayList<Integer> c;
		int p = -1;

		public Node()
		{
			c = new ArrayList<Integer>();
		}
		
		public int update()
		{
			if (c.size() == 0)
				return 0;
			
			int t = c.size();
			for (Integer i : c)
				t += nodes[i - 1].update();
			
			return t;
		}
	}

	public static void solve(int n, int num)
	{
		for (int i = 0; i < nodes[n - 1].c.size(); i++)
		{
			int val = num;

			for (int j = i - 1; j >= 0; j--)
				val -= (fam[nodes[n - 1].c.get(j) - 1] + 1);

			int a = val - fam[nodes[n - 1].c.get(i) - 1];

			System.out.print(" " + a);

			solve(nodes[n - 1].c.get(i), val);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		nodes = new Node[n];
		fam = new int[n];

		for (int i = 0; i < n; i++)
			nodes[i] = new Node();

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());

			fam[i] = k;

			for (int j = 0; j < k; j++)
			{
				int child = Integer.parseInt(st.nextToken());
				nodes[i].c.add(child);
				nodes[child - 1].p = i;
			}
		}

		for (int i = 0; i < n; i++)
			fam[i] = nodes[i].update();

		System.out.print(Math.min(1, n));

		Queue<Integer[]> q = new LinkedList<Integer[]>();
		q.add(new Integer[] { 1, n });

		while (!q.isEmpty())
		{
			Integer[] cur = q.poll();
			int node = cur[0];
			int num = cur[1];

			for (int i = 0; i < nodes[node - 1].c.size(); i++)
			{
				int val = num;

				for (int j = i - 1; j >= 0; j--)
					val -= (fam[nodes[node - 1].c.get(j) - 1] + 1);

				int a = val - fam[nodes[node - 1].c.get(i) - 1];

				System.out.print(" " + a);

				q.add(new Integer[] { nodes[node - 1].c.get(i), val });
			}
		}
	}
}
