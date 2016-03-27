package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: skidesign
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

class skidesign
{
	public static void main(String[] args) throws IOException
	{
		final Comparator<int[]> arrayComparator = new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2)
			{
				return o1[0] - o2[0];
			}
		};

		BufferedReader f = new BufferedReader(new FileReader("skidesign.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"skidesign.out")));

		int hills = Integer.parseInt(f.readLine());

		int[][] heights = new int[hills][2];

		for (int i = 0; i < hills; i++)
			heights[i][0] = Integer.parseInt(f.readLine());

		Arrays.sort(heights, arrayComparator);
		
		while (Math.abs(heights[0][0] - heights[hills - 1][0]) > 17)
		{
			heights[0][0]++;
			heights[0][1]++;
			heights[hills-1][0]--;
			heights[hills-1][1]++;
		}

		int cost = 0;

		for (int i = 0; i < hills; i++)
			cost += heights[i][1] * heights[i][1];
		
		out.println(cost);

		out.close();
		System.exit(0);
	}
}
