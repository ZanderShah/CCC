package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class PrimeFactorization
{

	public static boolean hasFactors = false;
	public static int y;
	static ArrayList<Integer> factors;

	public static void factorize(int n)
	{
		boolean gone = false;
		for (int i = 2; i <= Math.sqrt(n); i++)
			if (n % i == 0)
			{
				factors.add(i);
				factorize(n / i);
				hasFactors = true;
				gone = true;
				break;
			}

		if (!gone)
			factors.add(n);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());

		for (int i = 0; i < n; i++)
		{
			factors = new ArrayList<Integer>();
			st = new StringTokenizer(br.readLine());
			y = Integer.parseInt(st.nextToken());
			factorize(y);

			for (int j = 0; j < factors.size(); j++)
				if (j == factors.size() - 1)
					System.out.print(factors.get(j));
				else
					System.out.print(factors.get(j) + " ");
			
			if (i != n - 1)
				System.out.println();
		}
	}
}
