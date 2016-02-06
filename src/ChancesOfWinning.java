import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ChancesOfWinning
{
	public static int fav;
	public static int poss = 0;

	/**
	 * Runs through the game given the specific state and recursively determines
	 * all possible endings
	 * 
	 * @param play whether or not the teams have played
	 * @param points how many points each team has
	 */
	public static void sim(boolean[][] play, int[] points)
	{
		boolean[][] games = new boolean[play.length][play.length];
		int[] standings = new int[points.length];
		
		for (int i = 0; i < 4; i++)
		{
			standings[i] = points[i];
			
			for (int j = i + 1; j < 4; j++)
				games[i][j] = play[i][j];
		}
		
		boolean done = true;
		boolean leave = false;

		for (int i = 0; i < 4; i++)
			for (int j = i + 1; j < 4; j++)
				if (!games[i][j])
					done = false;

		if (done)
		{
			boolean won = true;

			for (int i = 0; i < 4; i++)
				if (i != fav && standings[fav] <= standings[i])
					won = false;

			if (won)
				poss++;
		}
		else
			for (int i = 0; i < 4 && !leave; i++)
			{
				for (int j = i + 1; j < 4 && !leave; j++)
				{
					if (!games[i][j])
					{
						games[i][j] = true;

						standings[i] += 3;
						sim(games, standings);
						standings[i] -= 3;

						standings[j] += 3;
						sim(games, standings);

						standings[j] -= 2;
						standings[i]++;
						sim(games, standings);

						leave = true;
					}
				}
			}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		fav = Integer.parseInt(br.readLine()) - 1;

		int games = Integer.parseInt(br.readLine());

		boolean[][] play = new boolean[4][4];
		int[] points = new int[4];

		for (int i = 0; i < games; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int sa = Integer.parseInt(st.nextToken());
			int sb = Integer.parseInt(st.nextToken());

			play[a][b] = true;

			if (sa > sb)
				points[a] += 3;
			else if (sb > sa)
				points[b] += 3;
			else
			{
				points[a]++;
				points[b]++;
			}
		}

		sim(play, points);
		System.out.println(poss);
	}
}
