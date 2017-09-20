package codeforces;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class BeautifulSubarrays
{
	static class Node
	{
		int rsz, lsz;
		Node l, r;

		Node()
		{
			rsz = lsz = 0;
			l = r = null;
		}
	}

	static void insert(Node n, int x, int lvl)
	{
		if (lvl < 0)
			return;

		int b = (x >> lvl) & 1;

		if (b == 0)
		{
			n.lsz++;
			if (n.l == null)
				n.l = new Node();
			insert(n.l, x, lvl - 1);
		}
		else
		{
			n.rsz++;
			if (n.r == null)
				n.r = new Node();
			insert(n.r, x, lvl - 1);
		}
	}

	static long query(Node n, int x, int lvl)
	{
		if (n == null || lvl < 0)
			return 0;

		long a = (k >> lvl) & 1, b = (x >> lvl) & 1;

		if (a == 1)
		{
			if (b == 1)
				return query(n.l, x, lvl - 1) + n.rsz;
			else
				return query(n.r, x, lvl - 1) + n.lsz;
		}
		else
		{
			if (b == 1)
				return query(n.r, x, lvl - 1);
			else
				return query(n.l, x, lvl - 1);
		}
	}

	static long k;

	public static void main(String[] args) throws Exception
	{
		long n = readInt();
		long ans = n * (n + 1) / 2;

		k = readLong();
		Node root = new Node();
		insert(root, 0, 31);

		for (int i = 0, p = 0; i < n; i++)
		{
			p ^= readInt();
			ans -= query(root, p, 31);
			insert(root, p, 31);
		}

		System.out.println(ans);
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
