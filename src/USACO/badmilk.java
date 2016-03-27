package USACO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class badmilk
{
	public static class milk
	{
		boolean bad = false;
		ArrayList<Integer> people = new ArrayList<Integer>();

		int[][] history;
	}

	public static void main(String[] args) throws Exception
	{
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("badmilk.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"badmilk.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());

		if (s == n)
			out.println(s);
		else
		{
			milk[] milk = new milk[m + 1];
			for (int i = 1; i <= m; i++)
			{
				milk[i] = new milk();
				milk[i].history = new int[101][n + 1];
			}

			for (int i = 0; i < d; i++)
			{
				st = new StringTokenizer(br.readLine());
				int p = Integer.parseInt(st.nextToken());
				int mi = Integer.parseInt(st.nextToken());
				int t = Integer.parseInt(st.nextToken());

				if (!milk[mi].people.contains(p))
					milk[mi].people.add(p);

				milk[mi].history[t][p] = 1;
			}

			ArrayList<Integer> infected = new ArrayList<Integer>();

			boolean[][] poss = new boolean[m + 1][n + 1];

			for (int i = 0; i < s; i++)
			{
				st = new StringTokenizer(br.readLine());
				int p = Integer.parseInt(st.nextToken());
				int t = Integer.parseInt(st.nextToken());
				infected.add(p);

				for (int k = 1; k <= m; k++)
					for (int j = t - 1; j >= 0; j--)
						if (milk[k].history[j][p] == 1)
							poss[k][p] = true;
			}

			for (int i = 1; i <= m; i++)
				for (Integer j : infected)
				{
					if (!poss[i][j])
						break;

					if (j == infected.get(infected.size() - 1))
						milk[i].bad = true;
				}

			ArrayList<Integer> meds = new ArrayList<Integer>();

			for (int i = 1; i <= m; i++)
				if (milk[i].bad)
					for (Integer j : milk[i].people)
						if (!meds.contains(j))
							meds.add(j);

			out.println(meds.size());
		}
		out.close();
	}
}
