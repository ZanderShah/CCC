package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class ZenGarden
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[] h = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < n; i++)
			h[i] = Integer.parseInt(st.nextToken());
		
		int m = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < m; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int d = Integer.parseInt(st.nextToken());
			
			if (h[a] < d || h[a + 1] < d)
				if (h[a] < h[a + 1])
					h[a] = 0;
				else
					h[a + 1] = 0;
			else
				h[a] -= d;
		}

		int t = 0;
		for (int i : h)
			t += i;
		System.out.println(t);
	}

}
