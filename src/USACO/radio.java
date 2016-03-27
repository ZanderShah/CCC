package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class radio
{
	public static int n, m;
	public static int[][] fpos, bpos, dp;

	public static int travel(int a, int b)
	{
		if (dp[a][b] != -1)
			return dp[a][b];
		
		if (a == n && b == m)
			return 0;

		int min = Integer.MAX_VALUE;

		if (a != n)
			min = Math.min(min, travel(a + 1, b) + dist(a + 1, b));
		if (b != m)
			min = Math.min(min, travel(a, b + 1) + dist(a, b + 1));
		if (a != n && b != m)
			min = Math.min(min, travel(a + 1, b + 1) + dist(a + 1, b + 1));

		return dp[a][b] = min;
	}

	public static int dist(int a, int b)
	{
		return (fpos[a][0] - bpos[b][0]) * (fpos[a][0] - bpos[b][0])
				+ (fpos[a][1] - bpos[b][1]) * (fpos[a][1] - bpos[b][1]);
	}

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("radio.in"));
		PrintWriter out = new PrintWriter(new FileWriter("radio.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		dp = new int[n + 1][m + 1];

		st = new StringTokenizer(br.readLine());
		int fx = Integer.parseInt(st.nextToken());
		int fy = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int bx = Integer.parseInt(st.nextToken());
		int by = Integer.parseInt(st.nextToken());

		String f = br.readLine();
		String b = br.readLine();
		fpos = new int[n + 1][2];
		fpos[0][0] = fx;
		fpos[0][1] = fy;
		bpos = new int[m + 1][2];
		bpos[0][0] = bx;
		bpos[0][1] = by;
		for (int i = 0; i < f.length(); i++)
			if (f.charAt(i) == 'N')
			{
				fpos[i + 1][0] = fpos[i][0];
				fpos[i + 1][1] = fpos[i][1] + 1;
			}
			else if (f.charAt(i) == 'S')
			{
				fpos[i + 1][0] = fpos[i][0];
				fpos[i + 1][1] = fpos[i][1] - 1;
			}
			else if (f.charAt(i) == 'E')
			{
				fpos[i + 1][0] = fpos[i][0] + 1;
				fpos[i + 1][1] = fpos[i][1];
			}
			else
			{
				fpos[i + 1][0] = fpos[i][0] - 1;
				fpos[i + 1][1] = fpos[i][1];
			}

		for (int i = 0; i < b.length(); i++)
			if (b.charAt(i) == 'N')
			{
				bpos[i + 1][0] = bpos[i][0];
				bpos[i + 1][1] = bpos[i][1] + 1;
			}
			else if (b.charAt(i) == 'S')
			{
				bpos[i + 1][0] = bpos[i][0];
				bpos[i + 1][1] = bpos[i][1] - 1;
			}
			else if (b.charAt(i) == 'E')
			{
				bpos[i + 1][0] = bpos[i][0] + 1;
				bpos[i + 1][1] = bpos[i][1];
			}
			else
			{
				bpos[i + 1][0] = bpos[i][0] - 1;
				bpos[i + 1][1] = bpos[i][1];
			}

		for (int i = 0; i < n + 1; i++)
			Arrays.fill(dp[i], -1);

		out.println(travel(0, 0));
		out.close();
	}
}
