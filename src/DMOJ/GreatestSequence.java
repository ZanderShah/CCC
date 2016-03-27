package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class GreatestSequence
{
	public static class Frequency
	{
		ArrayList<Integer> o = new ArrayList<Integer>();

		public Frequency()
		{

		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int k = Integer.parseInt(s[1]);
		int q = Integer.parseInt(s[2]);

		int[] sum = new int[n];
		Frequency[] freq = new Frequency[4001];
		for (int i = 0; i < 4001; i++)
			freq[i] = new Frequency();

		s = br.readLine().split(" ");
		for (int i = 0; i < n; i++)
		{
			sum[i] = Integer.parseInt(s[i]);

			freq[sum[i] + 2000].o.add(i);

			if (i != 0)
				sum[i] += sum[i - 1];
		}

		for (int query = 0; query < q; query++)
		{
			s = br.readLine().split(" ");
			int a = Integer.parseInt(s[0]) + 2000;
			int b = Integer.parseInt(s[1]) + 2000;
			int x = Integer.parseInt(s[2]) - 1;
			int y = Integer.parseInt(s[3]) - 1;

			if (freq[a].o.size() == 0 || freq[b].o.size() == 0)
				System.out.println("No");
			else if (x == 0)
			{
				if (sum[y] > k)
				{
					boolean findA = freq[a].o.get(0) <= y;
					boolean findB = freq[b].o.get(0) <= y;

					if (findA && findB)
						System.out.println("Yes");
					else
						System.out.println("No");
				}
				else
					System.out.println("No");
			}
			else if (sum[y] - sum[x - 1] > k)
			{
				int iA = Collections.binarySearch(freq[a].o, x);
				if (iA < 0)
					iA = -iA - 1;
				if (iA == freq[a].o.size())
					System.out.println("No");
				else
				{
					boolean findA = freq[a].o.get(iA) <= y;

					int iB = Collections.binarySearch(freq[b].o, x);

					if (iB < 0)
						iB = -iB - 1;
					if (iB == freq[b].o.size())
						System.out.println("No");
					else
					{
						boolean findB = freq[b].o.get(iB) <= y;

						if (findA && findB)
							System.out.println("Yes");
						else
							System.out.println("No");
					}
				}
			}
			else
				System.out.println("No");
		}
	}
}
