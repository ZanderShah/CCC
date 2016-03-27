package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Streetcars
{
	static int s;
	static int[] p;
	
	static int busses(int[] o, int MAX)
	{
		for (int r = 0; r < s; r++)
		{	
			int cur = 0;
			for (int i = 0; i < s; i++)
			{
				cur -= Math.max(cur * p[i] / 100, 0);

				if (cur + o[i] <= MAX)
				{
					cur += o[i];
					o[i] = 0;
				}
				else
				{
					o[i] -= (MAX - cur);
					cur = MAX;
				}
			}
			
			boolean done = true;

			for (int i = 0; i < s; i++)
				if (o[i] != 0)
					done = false;
			
			if (done)
			{
				return r + 1;
			}
		}
		
		return s;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = Integer.parseInt(br.readLine());

		int[] o = new int[s];
		int[] n = new int[s];
		p = new int[s];

		for (int i = 0; i < s; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			int per = Integer.parseInt(st.nextToken());

			o[i] = num;
			n[i] = num;
			p[i] = per;
		}

		System.out.println(busses(o, 132) - busses(n, 251));
	}

}
