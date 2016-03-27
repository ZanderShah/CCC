package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class speeding
{
	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("speeding.in"));
		PrintWriter out = new PrintWriter(new FileWriter("speeding.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[] limit = new int[101];
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());

			if (i == 0)
			{
				cur += Integer.parseInt(st.nextToken());
				int lim = Integer.parseInt(st.nextToken());
				for (int j = 0; j < cur; j++)
					limit[j] = lim;
			}
			else
			{
				int temp = Integer.parseInt(st.nextToken());
				int lim = Integer.parseInt(st.nextToken());

				for (int j = cur; j < temp + cur; j++)
					limit[j] = lim;
				
				cur += temp;
			}
		}

		cur = 0;
		int max = 0;
		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());

			int up = cur + Integer.parseInt(st.nextToken());
			int speed = Integer.parseInt(st.nextToken());

			for (int j = cur; j < up; j++)
			{
				if (speed > limit[j] && max < speed - limit[j])
					max = speed - limit[j];
			}

			cur = up;
		}

		out.println(max);
		out.close();
	}
}
