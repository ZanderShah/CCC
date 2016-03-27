package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: barn1
 */

import java.io.*;
import java.util.*;

class barn1
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("barn1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());

		int boards = Integer.parseInt(st.nextToken());
		int stalls = Integer.parseInt(st.nextToken());
		int cows = Integer.parseInt(st.nextToken());

		int[] block = new int[stalls + 1];
		int[] cowPlace = new int[cows];
		
		for (int i = 0; i < cows; i++)
		{
			cowPlace[i] = Integer.parseInt(f.readLine());
			block[cowPlace[i]]++;
		}
		
		Arrays.sort(cowPlace);
		
		for (int i = cowPlace[0]; i <= cowPlace[cows - 1]; i++)
			block[i]++;
		
		for (int i = 0; i < boards - 1; i++)
		{
			int cRun = 0;
			int cPlace = 0;
			int run = 0;
			int place = 0;
			
			for (int b = cowPlace[0]; b <= cowPlace[cows - 1]; b++)
			{
				if (block[b] == 1)
				{
					if (cRun == 0)
						cPlace = b;
					cRun++;
				}
				else
				{
					if (cRun > run)
					{
						run = cRun;
						place = cPlace;
					}
					cRun = 0;
				}
			}
			
			for (int p = place; p < place + run; p++)
				block[p] = 0;
		}
		
		int span = 0;
		for (int i = 0; i <= stalls; i++)
			if (block[i] > 0)
				span++;
		out.println(span);
		
		out.close();
		System.exit(0);
	}
}
