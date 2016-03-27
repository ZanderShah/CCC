package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Scribe
{
	public static int[] frequency(int n)
	{
		int[] f = new int[10];
		int m = n;
		int r = 1;
		
		if (n == 0)
			f[0] = 1;
		
		while (n > 0)
		{
			int cur = n % 10;
			
			for (int i = 0; i < 10; i++)
			{
				f[i] += (n / 10) * r;
				if (i < cur)
					f[i] += r;
			}
			
			f[cur] += (m % r) + 1;
			if (r != 1)
				f[0] -= r;
			n /= 10;
			r *= 10;
		}
		
		return f;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for (int essay = 0; essay < t; essay++)
		{
			String[] s = br.readLine().split(" ");
			int x = Integer.parseInt(s[0]) - 1;
			int y = Integer.parseInt(s[1]);

			int[] low = frequency(x);
			int[] high = frequency(y);
			
			for (int i = 0; i < 10; i++)
				if (i == 0)
					System.out.print(high[i] - low[i]);
				else
					System.out.print(" " + (high[i] - low[i]));

			if (essay + 1 != t)
				System.out.println();
		}

	}
}
