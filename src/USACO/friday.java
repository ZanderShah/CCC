package USACO;
/*
ID: zander.1
LANG: JAVA
PROG: friday
 */
import java.io.*;
import java.util.*;
public class friday
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("friday.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"friday.out")));
		int years = Integer.parseInt(f.readLine());
		int[] days = new int[7];
		int count = 1;
		int[] months = {31,28,31,30,31,30,31,31,30,31,30,31};
		for (int i = 0; i < years; i++)
			for (int m = 0; m < 12; m++)
				for (int d = 1; d <= months[m]; d++)
				{
					count++;
					
					if (d == 13)
						days[count % 7]++;		
					
					if (i % 4 == 0 && m == 1 && d == 28)
					{
						count++;
						
						if (i % 100 == 0 && (i + 1900) % 400 != 0)
							count--;
					}
				}
		out.println(days[0] + " " + days[1] + " " + days[2] + " " + days[3] + " " + days[4] + " " + days[5] + " " + days[6]);
		
		out.close();
		System.exit(0);
	}
}
