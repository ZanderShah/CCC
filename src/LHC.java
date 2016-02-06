import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * Brute-force approach which currently gets 8/20 points on dmoj.ca
 */
public class LHC
{
	static int n, maxN = 0, maxD = 0, maxS = 0;
	static Node[] nodes;
	static boolean[] v;

	static class Node
	{
		ArrayList<Integer> paths = new ArrayList<Integer>();

		Node()
		{

		}
	}

	static void search(int x, int d)
	{
		if (d > maxD)
		{
			maxD = d;
			maxN = x;
		}

		for (int i : nodes[x].paths)
			if (!v[i])
			{
				v[i] = true;
				search(i, d + 1);
				v[i] = false;
			}
	}
	
	static void count(int x, int d)
	{
		if (d == maxD)
			maxS++;
		
		for (int i : nodes[x].paths)
			if (!v[i])
			{
				v[i] = true;
				count(i, d + 1);
				v[i] = false;
			}
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());

		nodes = new Node[n];
		for (int i = 0; i < n; i++)
			nodes[i] = new Node();

		for (int i = 0; i < n - 1; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			nodes[a].paths.add(b);
			nodes[b].paths.add(a);
		}

		v = new boolean[n];
		v[0] = true;
		search(0, 0);

		maxD = 0;
		v = new boolean[n];
		v[maxN] = true;
		search(maxN, 0);
		
		for (int i = 0; i < n; i++)
		{
			v = new boolean[n];
			v[i] = true;
			count(i, 0);
		}

		System.out.println((maxD + 1) + " " + maxS / 2);
	}

}
