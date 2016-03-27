package USACO;
/*
ID: zander.1
LANG: JAVA
TASK: dualpal
 */
import java.io.*;
import java.util.*;

class dualpal
{
	public static String base(int num, int base)
	{
		return Integer.toString(num, base).toUpperCase();
	}

	public static boolean isPalindrome(String str)
	{
		return str.equals(new StringBuilder(str).reverse().toString());
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new
				FileReader("dualpal.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"dualpal.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());

		int n = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++)
		{
			int t = 0;

			for (int base = 2; base <= 10; base++)
				if (isPalindrome(base(start + 1, base)))
					t++;

			if (t >= 2)
				out.println(start + 1);
			else
				i--;

			start++;
		}

		out.close();
		System.exit(0);
	}
}
