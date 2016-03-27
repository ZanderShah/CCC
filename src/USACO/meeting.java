package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class meeting
{
	public static int n;

	public static void solve(int[][] g, ArrayList<Integer> s, int c, int t)
	{
		if (c == n - 1)
			s.add(t);
		else
			for (int i = 0; i < n; i++)
				if (g[c][i] != 0)
					solve(g, s, i, t + g[c][i]);
	}

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("meeting.in"));
		PrintWriter out = new PrintWriter(new FileWriter("meeting.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		int[][] bes = new int[n][n];
		ArrayList<Integer> dBes = new ArrayList<Integer>();
		int[][] els = new int[n][n];
		ArrayList<Integer> dEls = new ArrayList<Integer>();

		int m = Integer.parseInt(st.nextToken());

		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;

			bes[a][b] = Integer.parseInt(st.nextToken());
			els[a][b] = Integer.parseInt(st.nextToken());
		}

		solve(bes, dBes, 0, 0);
		solve(els, dEls, 0, 0);

		int min = Integer.MAX_VALUE;

		for (int i = 0; i < dBes.size(); i++)
			for (int j = 0; j < dEls.size(); j++)
				if (dBes.get(i).equals(dEls.get(j)) && dBes.get(i) < min)
					min = dBes.get(i);

		if (min == Integer.MAX_VALUE)
			out.println("IMPOSSIBLE");
		else
			out.println(min);
		out.close();
	}

}
