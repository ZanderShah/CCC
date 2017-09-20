package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class NotEnoughTesters
{
	public static class divs
	{
		ArrayList<Integer> c = new ArrayList<Integer>();
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		divs[] factors = new divs[100000];

		for (int i = 0; i < 100000; i++)
			factors[i] = new divs();

		factors[0].c.add(1);

		for (int i = 1; i < 100000; i++)
		{
			ArrayList<Integer> div = new ArrayList<Integer>();

			for (int j = 1; j <= Math.sqrt(i + 1); j++)
				if ((i + 1) % j == 0)
				{
					div.add(j);
					if (j * j != i + 1)
						div.add((i + 1) % j);
				}

			factors[div.size() - 1].c.add(i + 1);
		}

		for (int c = 0; c < t; c++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			System.out.println(Math.abs(Collections.binarySearch(factors[k - 1].c, b) + 1)
					- Math.abs(Collections.binarySearch(factors[k - 1].c, a - 1) + 1));
		}
	}
}