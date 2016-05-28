package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MaximumProduct
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		if (n == 1)
			System.out.println(Integer.parseInt(br.readLine()));
		else
		{
			int min = Integer.MIN_VALUE;

			int p = 1;
			int nZero = 0;

			for (int i = 0; i < n; i++)
			{
				int a = Integer.parseInt(br.readLine());
				if (a != 0)
					p *= a;
				else
					nZero++;

				if (a < 0 && a > min)
					min = a;
			}

			if (nZero == n)
				System.out.println(0);
			else
			{
				if (p < 0 && nZero != n - 1)
					p /= min;
				else if (p < 0 && nZero == n - 1)
					p = 0;

				System.out.println(p);
			}
		}
	}

}
