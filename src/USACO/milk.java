package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: milk
 */

import java.io.*;
import java.util.*;

class milk
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("milk.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"milk.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		int totalMilk = Integer.parseInt(st.nextToken());
		int farmers = Integer.parseInt(st.nextToken());

		int[] cost = new int[farmers];
		int[] units = new int[farmers];

		for (int i = 0; i < farmers; i++)
		{
			st = new StringTokenizer(f.readLine());
			cost[i] = Integer.parseInt(st.nextToken());
			units[i] = Integer.parseInt(st.nextToken());
		}

		int small = 0;
		int temp1;
		int temp2;

		for (int i = 0; i < farmers - 1; i++)
		{
			for (int j = i; j < farmers; j++)
				if (cost[j] < cost[small])
					small = j;

			temp1 = cost[i];
			temp2 = units[i];
			cost[i] = cost[small];
			units[i] = units[small];
			cost[small] = temp1;
			units[small] = temp2;
		}

		int totalCost = 0;
		
		for (int i = 0; totalMilk > 0; i++)
		{
			if (totalMilk - units[i] >= 0)
			{
				totalMilk -= units[i];
				totalCost += units[i] * cost[i];
			}
			else
			{
				totalCost += totalMilk * cost[i];
				totalMilk = 0;
			}
		}

		out.println(totalCost);
		out.close();
		System.exit(0);
	}
}
