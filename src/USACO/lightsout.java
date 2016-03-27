package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class lightsout
{
	public final static int HORIZONTAL = 0;
	public final static int VERTICAL = 1;
	public static int n, total;
	public static int[][] e;
	public static int[] distinct = new int[200001];

	public static int lit(int i)
	{
		int counter = 0;
		for (int j = 0; j < i; j++)
			counter += e[j][0];

		int clock = 0;
		for (int j = i; j < n; j++)
			clock += e[j][0];

		return Math.min(counter, clock);
	}

	public static int unlit(int i)
	{

		int clock = 0;
		for (int j = i; j < n - 1; j++)
		{
			clock += e[j][0];
			if (distinct[e[j][0]] == 1)
			{
				clock += lit(j + 1);
				break;
			}
			
		}
		
		return clock;
	}

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("lightsout.in"));
		PrintWriter out = new PrintWriter(new FileWriter("lightsout.out"));

		n = Integer.parseInt(br.readLine());

		int[][] p = new int[n][2];
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			p[i][0] = Integer.parseInt(st.nextToken());
			p[i][1] = Integer.parseInt(st.nextToken());
		}

		e = new int[n][2];

		for (int i = 0; i < n; i++)
		{
			if (i != n - 1)
				if (p[i][0] == p[i + 1][0])
				{
					e[i][1] = VERTICAL;
					e[i][0] = Math.abs(p[i][1] - p[i + 1][1]);
				}
				else
				{
					e[i][1] = HORIZONTAL;
					e[i][0] = Math.abs(p[i][0] - p[i + 1][0]);
				}
			else if (p[i][0] == p[0][0])
			{
				e[i][1] = VERTICAL;
				e[i][0] = Math.abs(p[i][1] - p[0][1]);
			}
			else
			{
				e[i][1] = HORIZONTAL;
				e[i][0] = Math.abs(p[i][0] - p[0][0]);
			}

			total += e[i][0];
			if (i != 0 && i != n - 1)
				distinct[e[i][0]]++;
		}

		int max = 0;
		for (int i = 1; i < n; i++)
			max = Math.max(max, unlit(i) - lit(i));

		out.println(max);
		out.close();
	}
}
