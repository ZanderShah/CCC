package TSOC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AlexAndAnimalRights
{
	public static int r, c;
	public static int cages = 0;
	public static char[][] grid;
	
	public static void search(int i, int j)
	{
		if (grid[i][j] == 'M' || grid[i][j] == '.')
		{
			grid[i][j] = 'X';
			 
			if (i - 1 >= 0)
				search(i - 1, j);
			if (i + 1 < r)
				search(i + 1, j);
			if (j - 1 >= 0)
				search(i, j - 1);
			if (j + 1 < c)
				search(i, j + 1);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		grid = new char[r][c];
		for (int i = 0; i < r; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < c; j++)
				grid[i][j] = s.charAt(j);
		}

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				if (grid[i][j] == 'M')
				{
					cages++;
					search(i, j);
				}

		System.out.println(cages);
	}

}
