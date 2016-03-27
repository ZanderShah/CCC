package USACO;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class cowroute
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new FileReader("cowroute.in"));
		//PrintWriter out = new PrintWriter(new FileWriter("cowroute.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		
		int n = Integer.parseInt(st.nextToken());
		int min = Integer.MAX_VALUE;
		
		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			
			int c = Integer.parseInt(st.nextToken());
			
			int t = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(br.readLine());
			boolean h = false;
			
			for (int j = 0; j < t; j++)
			{
				int r = Integer.parseInt(st.nextToken());
				
				if (r == a)
					h = true;
				
				if (r == b && h)
					if (c < min)
						min = c;
			}
		}
		
		if (min == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(min);

	}

}
