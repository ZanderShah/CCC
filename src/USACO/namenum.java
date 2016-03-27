package USACO;
/*
ID: zander.1
LANG: JAVA
TASK: namenum
 */
import java.io.*;
import java.util.*;

class namenum
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("namenum.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"namenum.out")));

		String num = f.readLine();

		int[] reverse = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7,
				7, 8, 8, 8, 9, 9, 9, 0 };

		BufferedReader r = new BufferedReader(new FileReader("dict.txt"));

		String[] st = new String[4617];
		String[] nums = new String[4617];

		for (int n = 0; n < st.length; n++)
		{
			st[n] = r.readLine();
			nums[n] = "";

			for (int i = 0; i < st[n].length(); i++)
				nums[n] += reverse[st[n].charAt(i) - 'A'];
		}

		int n = 0;
		for (int i = 0; i < nums.length; i++)
			if (num.equals(nums[i]))
			{
				out.println(st[i]);
				n++;
			}

		if (n == 0)
			out.println("NONE");

		out.close();
		System.exit(0);
	}
}
