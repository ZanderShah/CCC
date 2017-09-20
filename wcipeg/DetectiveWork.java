package wcipeg;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class DetectiveWork
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		char[][] map = new char[n][m];

		for (int i = 0; i < n; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < m; j++)
				map[i][j] = s.charAt(j);
		}

		int cost = 0;
		BigInteger poss = new BigInteger("1");

		for (int i = 0; i < m; i++)
		{
			int[] freq = new int[26];
			int q = 0;
			int max = 0;
			long same = 1;

			for (int j = 0; j < n; j++)
				if (map[j][i] == '?')
					q++;
				else
				{
					int spot = map[j][i] - 'A';
					freq[spot]++;
					if (freq[spot] > max)
					{
						max = freq[spot];
						same = 1;
					}
					else if (freq[spot] == max)
						same++;
				}

			if (max == 0)
				same = 26;

			cost += (n - max - q);
			poss = poss.multiply(new BigInteger(String.valueOf(same)));
		}

		System.out.println(cost + " " + poss.mod(new BigInteger("1000")));
	}

}
