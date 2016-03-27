package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class balancing
{
	public static class Cow implements Comparable<Cow>
	{
		int t, x, y;
		public Cow(int t, int x, int y)
		{
			this.t = t;
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Cow c)
		{
			return x - c.x;
		}
	}
	
	public static class Cow2 implements Comparable<Cow2>
	{
		int t, x, y;
		public Cow2(int t, int x, int y)
		{
			this.t = t;
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Cow2 c)
		{
			return y - c.y;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
		PrintWriter out = new PrintWriter(new FileWriter("balancing.out"));
		
		int n = Integer.parseInt(br.readLine());
		Cow[] cows = new Cow[n];
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			cows[i] = new Cow(i, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		Arrays.sort(cows);
		
		int c = n / 2;	
		while (c - 1 >= 0 && cows[c - 1].x == cows[c].x)
			c--;
		int x1 = c;
		c = n / 2;
		while (c + 1 < n && cows[c + 1].x == cows[c].x)
			c++;
		int x2 = c;

		HashMap<Integer, Integer> cowMap1 = new HashMap<Integer, Integer>();
		for (int i = 0; i <= x1; i++)
			cowMap1.put(cows[i].t, 0);
		for (int i = x1 + 1; i < n; i++)
			cowMap1.put(cows[i].t, 1);
		HashMap<Integer, Integer> cowMap2 = new HashMap<Integer, Integer>();
		for (int i = 0; i <= x2; i++)
			cowMap2.put(cows[i].t, 0);
		for (int i = x2 + 1; i < n; i++)
			cowMap2.put(cows[i].t, 1);
		
		Cow2[] cows2 = new Cow2[n];
		for (int i = 0; i < n; i++)
			cows2[i] = new Cow2(cows[i].t, cows[i].x, cows[i].y);
		Arrays.sort(cows2);

		int max = Integer.MAX_VALUE;
		int upLeft1 = 0;
		int upRight1 = 0;
		int upLeft2 = 0;
		int upRight2 = 0;
		
		for (int i = 0; i < n; i++)
		{
			if (cowMap1.get(cows2[i].t) == 0)
				upLeft1++;
			else
				upRight1++;
			if (cowMap2.get(cows2[i].t) == 0)
				upLeft2++;
			else
				upRight2++;
			
			int min1 = Math.max(upLeft1, Math.max(upRight1, Math.max(x1 - upLeft1, n - x1 - upRight1)));
			int min2 = Math.max(upLeft2, Math.max(upRight2, Math.max(x2 - upLeft2, n - x2 - upRight2)));
			max = Math.min(max, Math.min(min1, min2));
		}
		
		out.println(max);
		out.close();
	}
}
