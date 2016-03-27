package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class cowjog
{

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("cowjog.in"));
		PrintWriter out = new PrintWriter(new FileWriter("cowjog.out"));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] c = new int[n];
		
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();
			c[i] = Integer.parseInt(st.nextToken());
		}

		int t = 0;
		int m = Integer.MAX_VALUE;
		
		for (int i = n - 1; i >= 0; i--)
			if (c[i] <= m)
			{
				t++;
				m = c[i];
			}
		
		out.println(t);
		out.close();
		
	}

}
