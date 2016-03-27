package WCIPEG;
import java.io.*;

public class WoburnWildcats
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		double[] letters = new double[11];

		for (int i = 0; i < 11; i++)
			letters[i] = Integer.parseInt(br.readLine());

		int min = 0;

		for (int i = 1; i < 8; i++)
			if (letters[i] < letters[min])
				min = i;

		while (letters[10] != 0)
		{
			for (int i = 0; i < 8; i++)
			{
				if (letters[i] < letters[min])
					min = i;

				if (letters[i] <= letters[min])
				{
					if (i != 1 && i != 5)
					{
						if (letters[9] > 0)
						{
							letters[i]++;
							letters[9]--;
						}
						else if (letters[10] > 0)
						{
							letters[i]++;
							letters[10]--;
						}
					}
					else
					{
						if (letters[8] > 0)
						{
							letters[i]++;
							letters[8]--;
						}
						else if (letters[10] > 0)
						{
							letters[i]++;
							letters[10]--;
						}
					}
				}
			}
		}
		for (int i = 1; i < 8; i++)
			if (letters[i] < letters[min])
				min = i;

		System.out.println((int) (letters[min]));
	}
}
