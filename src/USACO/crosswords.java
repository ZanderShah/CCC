package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class crosswords
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("crosswords.in"));
		PrintWriter out = new PrintWriter(new FileWriter("crosswords.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] g = new int[n][m];

		for (int i = 0; i < n; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < m; j++)
				if (s.charAt(j) == '#')
					g[i][j] = 1;
		}

		ArrayList<Integer[]> pts = new ArrayList<Integer[]>();

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if ((i == 0 || g[i - 1][j] == 1) && g[i][j] != 1
						&& g[i][j] != 2 && i + 2 < n)
				{
					if (g[i + 1][j] != 1 && g[i + 2][j] != 1)
					{
						pts.add(new Integer[] { i, j });
						g[i][j] = 2;
					}
				}
				if ((j == 0 || g[i][j - 1] == 1) && g[i][j] != 1
						&& g[i][j] != 2 && j + 2 < m)
					if (g[i][j + 1] != 1 && g[i][j + 2] != 1)
					{
						pts.add(new Integer[] { i, j });
						g[i][j] = 2;
					}
			}

		out.println(pts.size());
		for (Integer[] p : pts)
			out.println((p[0] + 1) + " " + (p[1] + 1));
		
		out.close();
	}
}
