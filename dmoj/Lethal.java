package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Lethal
{
	public static int n, t, closest = Integer.MAX_VALUE;
	public static int[] m;

	public static void close(int i, int d)
	{
		if (d < closest)
		{
			if (i == n)
			{
				if (d >= t)
					closest = d;
			}
			else
			{
				close(i + 1, d + m[i]);
				close(i + 1, d);
			}
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int g = Integer.parseInt(br.readLine());

		for (int game = 0; game < g; game++)
		{
			n = Integer.parseInt(br.readLine());
			m = new int[n];
			int total = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++)
			{
				m[i] = Integer.parseInt(st.nextToken());
				total += m[i];
			}

			st = new StringTokenizer(br.readLine());
			int h = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			
			close(0, 0);
			
			if (total - closest >= h)
				System.out.println("LETHAL");
			else
				System.out.println("NOT LETHAL");
			
			closest = Integer.MAX_VALUE;
		}
	}

}
