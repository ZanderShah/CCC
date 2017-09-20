package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MarciaAndMaze
{
	public static char[][] g;

	public static boolean valid(int a, int b, int x)
	{
		for (int i = 0; i < x; i++)
			if (g[a + i][b] == '#' || g[a][b + i] == '#'
					|| g[a + x - 1][b + i] == '#'
					|| g[a + i][b + x - 1] == '#')
				return false;

		return true;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		g = new char[n][n];

		for (int i = 0; i < n; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < n; j++)
				g[i][j] = s.charAt(j);
		}

		int x = 1;
		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int r = n - Math.max(i, j); r > x; r--)
					if (valid(i, j, r))
						x = r;

		System.out.println(x - 1);

	}

}
