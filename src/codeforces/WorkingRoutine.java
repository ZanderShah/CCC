package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class WorkingRoutine
{
	static class Node
	{
		int v;
		Node down, right;
	}

	static Node getNode(int x, int y)
	{
		Node ret = head;
		for (int i = 0; i < x; i++)
			ret = ret.down;
		for (int i = 0; i < y; i++)
			ret = ret.right;
		return ret;
	}

	static void cutLinks(Node leftCut, Node topCut, int h, int w)
	{
		for (int i = 1; i < h; i++, leftCut = leftCut.down)
			leftCut.right = null;
		Node bottomCut = leftCut.right;
		leftCut.right = null;
		for (int i = 0; i < w; i++, bottomCut = bottomCut.right)
			bottomCut.down = null;

		for (int i = 1; i < w; i++, topCut = topCut.right)
			topCut.down = null;
		Node rightCut = topCut.down;
		topCut.down = null;
		for (int i = 0; i < h; i++, rightCut = rightCut.down)
			rightCut.right = null;
	}

	static void makeLinks(Node leftLink, Node topLink, Node cur, int h, int w)
	{
		Node leftFollower = cur, topFollower = cur;

		for (int i = 1; i < h; i++, leftLink = leftLink.down, leftFollower = leftFollower.down)
			leftLink.right = leftFollower;
		leftLink.right = leftFollower;
		leftLink = leftLink.down.right;
		for (int i = 0; i < w; i++, leftLink = leftLink.right, leftFollower = leftFollower.right)
			leftFollower.down = leftLink;

		for (int i = 1; i < w; i++, topLink = topLink.right, topFollower = topFollower.right)
			topLink.down = topFollower;
		topLink.down = topFollower;

		topLink = topLink.right.down;
		for (int i = 0; i < h; i++, topLink = topLink.down, topFollower = topFollower.down)
			topFollower.right = topLink;
	}

	static Node head;

	public static void main(String[] args) throws Exception
	{
		int n = readInt(), m = readInt(), q = readInt();
		// Extra row and column for buffer
		int[][] g = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				g[i][j] = readInt();

		// Initialise buffer row and column
		head = new Node();
		Node cur = head;
		for (int i = 0; i <= n; i++, cur = cur.down)
			cur.down = new Node();
		cur = head;
		for (int i = 0; i <= m; i++, cur = cur.right)
			cur.right = new Node();

		cur = head;
		// Insert values into linked list
		for (int i = 0; i <= n; i++, cur = cur.down)
		{
			Node up = cur.right, left = cur.down;
			for (int j = 0; j <= m; j++, up = up.right, left = left.right)
			{
				up.down = left.right = new Node();
				up.down.v = g[i][j];
			}
		}

		for (int i = 0; i < q; i++)
		{
			int x1 = readInt() - 1, y1 = readInt() - 1, x2 = readInt() - 1, y2 = readInt() - 1;
			Node a = getNode(x1, y1), b = getNode(x2, y2);
			if (x1 > x2)
			{
				Node t = a;
				a = b;
				b = t;
			}
			int h = readInt(), w = readInt();

			Node aDown = a.down, aRight = a.right;
			Node bDown = b.down, bRight = b.right;
			Node tempA = a.right.down, tempB = b.right.down;

			// Make new links to swap the rectangles
			makeLinks(aDown, aRight, tempB, h, w);
			makeLinks(bDown, bRight, tempA, h, w);
		}

		cur = head.right.down;
		for (; cur.down != null; cur = cur.down)
		{
			for (Node i = cur; i.right != null; i = i.right)
				out.print(i.v + " ");
			out.println();
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
