package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ChemistryHomework
{
	static int n, m, h = 0, c = 0;
	static long e = 0;
	static int[] t;
	static int[][] g;
	static boolean[] vis;
	static boolean possible = true;

	static void tag(int x)
	{
		if (possible)
		{
			int bonds = 0;
			for (int i = 0; i < n; i++)
				bonds += g[x][i];
			if (bonds == 1 || bonds == 4)
			{
				t[x] = bonds;
				if (bonds == 1)
					h++;
				else
					c++;
			}
			else
				possible = false;
		}
	}

	static void energy(int x)
	{
		for (int i = 0; i < n; i++)
			if (g[x][i] == 1 && t[x] == t[i])
				e += 346;
			else if (g[x][i] == 2)
				e += 615;
			else if (g[x][i] == 1)
				e += 413;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		m = Integer.parseInt(br.readLine());

		g = new int[n][n];

		for (int i = 0; i < m; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			g[a][b]++;
			g[b][a]++;
		}

		// 1 == Hydrogen, 4 == Carbon
		t = new int[n];

		for (int i = 0; i < n; i++)
			tag(i);

		if (!possible)
			System.out.println("Impossible");
		else
		{
			for (int i = 0; i < n; i++)
				energy(i);

			System.out.println(e / 2);

			if (c == 1)
				System.out.printf("CH%d", h);
			else if (h == 1)
				System.out.printf("C%dH", c);
			else
				System.out.printf("C%dH%d", c, h);
		}
	}
}
