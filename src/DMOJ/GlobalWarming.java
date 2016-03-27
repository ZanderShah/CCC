package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class GlobalWarming
{
	static int n;
	static int[] d;

	static boolean check(int k)
	{
		int[] c = new int[k];
		for (int i = 0; i < k; i++)
			c[i] = d[i];

		for (int i = k; i < n - 1; i++)
			if (d[i] != c[i % k])
				return false;

		return true;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());

		while (n != 0)
		{
			if (n == 1)
				System.out.println(0);
			else
			{
				int l = Integer.parseInt(st.nextToken());

				d = new int[n - 1];

				for (int i = 0; i < n - 1; i++)
				{
					int f = Integer.parseInt(st.nextToken());
					d[i] = f - l;
					l = f;
				}

				boolean c = false;
				
				for (int i = 1; i < n - 1 && !c; i++)
					if (check(i))
					{
						System.out.println(i);
						c = true;
					}
				
				if (!c)
					System.out.println(n - 1);

			}

			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
		}

	}

}
