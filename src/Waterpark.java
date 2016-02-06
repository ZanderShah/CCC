import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Waterpark
{
	public static class Point
	{
		ArrayList<Integer> paths = new ArrayList<Integer>();
	}
	
	public static Point[] points;
	public static int[] dp;
	public static int n;

	/**
	 * Performs a dfs of the graph, memoizing answers
	 * 
	 * @param c the current spot on the slide
	 * @return the number of total number of ways
	 */
	public static int slide(int c)
	{
		if (dp[c] == 0)
		{
			if (c == n - 1)
				dp[c] = 1;
			else
				for (int i = 0; i < points[c].paths.size(); i++)
					if (c < points[c].paths.get(i))
						dp[c] += slide(points[c].paths.get(i));
		}
		return dp[c];
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		
		points = new Point[n];
		
		for (int i = 0; i < n; i++)
			points[i] = new Point();

		dp = new int[n];

		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());

		while (a != 0)
		{
			points[a - 1].paths.add(b - 1);
			points[b - 1].paths.add(a - 1);

			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
		}

		System.out.println(slide(0));
	}

}
