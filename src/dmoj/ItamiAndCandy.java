package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ItamiAndCandy
{
	/**
	 * Prime Number Sieve taken off StackOverflow
	 * @param max largest possible prime
	 * @return an array of primes between 0 and max
	 */
	private static int[] generatePrimes(int max)
	{
		boolean[] isComposite = new boolean[max + 1];
		for (int i = 2; i * i <= max; i++)
		{
			if (!isComposite[i])
			{
				for (int j = i; i * j <= max; j++)
				{
					isComposite[i * j] = true;
				}
			}
		}
		int numPrimes = 0;
		for (int i = 2; i <= max; i++)
		{
			if (!isComposite[i])
				numPrimes++;
		}
		int[] primes = new int[numPrimes];
		int index = 0;
		for (int i = 2; i <= max; i++)
		{
			if (!isComposite[i])
				primes[index++] = i;
		}
		return primes;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int x = Integer.parseInt(st.nextToken());

		int[] primes = generatePrimes(n);

		int poss = 0;

		// Goes through every prime number and calculates the number of possibilities
		// assuming either 0 or 1 pieces of candy are taken by the third friend
		for (int i = 0; i < primes.length; i++)
		{
			poss += (n - primes[i]) / x + 1;
			if (n - primes[i] > 0)
				poss += (n - primes[i] - 1) / x + 1;
		}

		System.out.println(poss);
	}
}
