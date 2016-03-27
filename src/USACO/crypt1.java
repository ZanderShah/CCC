package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: crypt1
 */
import java.io.*;
import java.util.*;

class crypt1
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("crypt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"crypt1.out")));
		
		int n = Integer.parseInt(f.readLine());
		int[] nums = new int[n];
		StringTokenizer st = new StringTokenizer(f.readLine());
		
		for (int i = 0; i < n; i++)
			nums[i] = Integer.parseInt(st.nextToken());
		
		out.close();
		System.exit(0);
	}
}
