package vmss;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class NewPrimeFactorization
{
	public static boolean hasFactors = false;
	public static int y;

	public static void factorize(int n)
	{
		boolean gone = false;
		for (int i = 2; i <= Math.sqrt(n); i++)
		{
			if (n % i == 0)
			{
				System.out.println(i);
				factorize(n / i);
				hasFactors = true;
				gone = true;
				break;
			}
		}

		if (!gone && n != y)
			System.out.println(n);
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		y = Integer.parseInt(br.readLine());
		factorize(y);

		if (!hasFactors && y != 1)
			System.out.println(y);
	}

}
