package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class ArithmeticSnowman
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] size = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			size[i] = Integer.parseInt(st.nextToken());

		Arrays.sort(size);

		int max = 0;

		if (n <= 100)
			for (int i = 0; i < n - 2; i++)
			{
				ArrayList<Integer> diff = new ArrayList<Integer>();

				for (int j = i + 1; j < n; j++)
				{
					int d = size[j] - size[i];
					diff.add(d);

					int s = -1;

					if (d % 2 == 0 && d != 0)
						s = Collections.binarySearch(diff, d / 2);
					else if (d == 0)
						if (diff.get(diff.size() - 1) == 0)
							s = diff.size() - 2;

					if (s >= 0 && s != diff.size() - 1)
						max = Math.max(max, size[i] + size[s + 1 + i]
								+ size[j]);
				}
			}
		else
			for (int i = 0; i < n - 3; i++)
			{
				ArrayList<Integer> diff = new ArrayList<Integer>();
				for (int j = i + 1; j < n; j++)
				{
					int d = size[j] - size[i];

					diff.add(d);

					if (d % 2 == 0)
					{
						int s = Collections.binarySearch(diff, d / 2);

						if (s >= 0)
							max = Math.max(max, size[i] + size[s + 1 + i] + size[j]);

					}
				}
			}

		System.out.println(max);
	}
}