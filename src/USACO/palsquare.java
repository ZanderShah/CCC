package USACO;
/*
ID: zander.1
LANG: JAVA
TASK: palsquare
 */
import java.io.*;
import java.util.*;

class palsquare
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
				FileReader("palsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"palsquare.out")));

		int base = Integer.parseInt(f.readLine());

		for (int i = 1; i <= 300; i++)
		{
			String b = base(i, base);
			String s = base(i * i, base);
			if (isPalindrome(s))
				out.println(b + " " + s);
		}

		out.close();
		System.exit(0);
	}
}
