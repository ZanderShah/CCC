package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Pollos
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());

		int[] r = new int[n + 1];
		boolean[] s = new boolean[n + 1];
		int[] d = new int[n + 1];

		int c = 1;
		for (int i = 1; i <= n; i++)
		{
			st = new StringTokenizer(br.readLine());
			r[i] = Integer.parseInt(st.nextToken());
			s[i] = st.nextToken().charAt(0) == '1';

			d[i] = r[i] - r[i - 1];

			if (!s[i - 1])
				d[i] += d[i - 1];
			else
				c++;
		}

		if (c > k)
			System.out.println("DEA Bust!");
		else
		{
			int max = 0;
			int omax = 1000001;
			int e = 0;
			boolean broke = false;
			while (c < k)
			{
				c++;
				for (int i = 2; i <= n; i++)
				{
					if (i >= omax && i <= n)
						if (d[i] >= d[omax] && !broke)
							d[i] += e;
						else
							broke = true;
					if (d[max] < d[i] && d[i] > r[i] - r[i - 1])
						max = i;
				}

				if (max == 0)
					break;
				broke = false;
				omax = max;
				e = -d[max] + (r[max] - r[max - 1]);
			}
			
			max = 0;
			for (int i = 1; i <= n; i++)
			{
				if (i >= omax && i <= n)
					if (d[i] >= d[omax] && !broke)
						d[i] += e;
					else
						broke = true;
				// System.out.print(d[i] + " ");
				if (d[max] < d[i])
					max = i;
			}

			System.out.println(d[max]);
		}
	}

}
