package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class bcount
{

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("bcount.in"));
		PrintWriter out = new PrintWriter(new FileWriter("bcount.out"));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		
		int[][] cows = new int[n][3];
		
		cows[0][Integer.parseInt(br.readLine()) - 1]++;
		
		for (int i = 1; i < n; i++)
		{
			cows[i][Integer.parseInt(br.readLine()) - 1]++;
			cows[i][0] += cows[i - 1][0];
			cows[i][1] += cows[i - 1][1];
			cows[i][2] += cows[i - 1][2];
		}
		
		for (int i = 0; i < q; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;

			if (a == 0)
				out.println(cows[b][0] + " " + cows[b][1] + " " + cows[b][2]);
			else
				out.println((cows[b][0] - cows[a - 1][0]) + " " + (cows[b][1] - cows[a - 1][1]) + " " + (cows[b][2] - cows[a - 1][2]));
		}
		
		out.close();
	}
}
