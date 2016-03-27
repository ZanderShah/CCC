package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class hopscotch
{
	private static int move(int r, int c)
	{
		if (r == grid.length - 1 && c == grid[0].length - 1)
			return 1;
		
		int t = 0;
		
		for (int i = r + 1; i < grid.length; i++)
			for (int j = c + 1; j < grid[0].length; j++)
				if (grid[i][j] != grid[r][c])
					t += move(i, j);
		
		return t;
	}
	
	static boolean[][] grid;
	
	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("hopscotch.in"));
		PrintWriter out = new PrintWriter(new FileWriter("hopscotch.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		
		grid = new boolean[r][c];
		
		for (int i = 0; i < r; i++)
		{
			String s = br.readLine();
		
			for (int j = 0; j < c; j++)
				grid[i][j] = (s.charAt(j) == 'R') ;
		}
		
		//System.out.println(move(0, 0));
		
		out.println(move(0, 0));
		out.close();
	}

}
