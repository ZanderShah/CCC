package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: gift1
 */
import java.io.*;
import java.util.*;

class gift1
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("gift1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"gift1.out")));
		int NP = Integer.parseInt(f.readLine());
		String[] n = new String[NP];
		int[] m = new int[NP];
		for (int i = 0; i < n.length; i++)
			n[i] = f.readLine();
		while (f.ready())
		{
			int g = java.util.Arrays.asList(n).indexOf(f.readLine());
			StringTokenizer st = new StringTokenizer(f.readLine());
			int a = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			if (p != 0)
			{
				m[g] -= (a - a % p);
				for (int i = 1; i <= p; i++)
					m[java.util.Arrays.asList(n).indexOf(f.readLine())] += a
							/ p;
			}
		}
		for (int i = 0; i < n.length; i++)
			out.println(n[i] + " " + m[i]);
		out.close();
		System.exit(0);
	}
}
