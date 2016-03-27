package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: combo
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

class combo
{
	public static ArrayList<String> combo = new ArrayList<String>();
	public static int n;

	public static void main(String[] args) throws Exception
	{
		BufferedReader f = new BufferedReader(new FileReader("combo.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"combo.out")));

		n = Integer.parseInt(f.readLine());

		StringTokenizer st = new StringTokenizer(f.readLine());
		String c = st.nextToken();
		c += " " + st.nextToken();
		c += " " + st.nextToken();

		st = new StringTokenizer(f.readLine());
		String m = st.nextToken();
		m += " " + st.nextToken();
		m += " " + st.nextToken();

		permutation("", c);
		permutation("", m);

		if (n == 1)
			out.println(1);
		else
			out.println(combo.size());
		out.close();
		System.exit(0);
	}

	public static void permutation(String result, String given)
	{
		if (given.length() == 0)
		{
			if (!combo.contains(result))
				combo.add(result);
			return;
		}
		for (int i = -2; i <= 2; i++)
		{
			StringTokenizer st = new StringTokenizer(given);
			String k = st.nextToken();
			int s = Integer.parseInt(k) + i;

			if (s > n)
				s -= n;
			else if (s < 1)
				s += n;

			if (k.length() != given.length())
				permutation(result + s + " ", given.substring(k.length() + 1));
			else
				permutation(result + s + " ", "");
		}
	}
}
