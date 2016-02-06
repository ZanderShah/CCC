import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class AbsolutelyAcidic
{

	public static void main(String[] args) throws Exception
	{
		// A method to sort the 2d array because I did not realize sorting objects
		// was easier at the time
		final Comparator<int[]> frequency = new Comparator<int[]>() {
			public int compare(int[] a, int[] b)
			{
				return a[0] - b[0];
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[][] freq = new int[1001][2];

		for (int i = 0; i < 1001; i++)
			freq[i][1] = i;

		// Updates the frequency
		for (int i = 0; i < n; i++)
		{
			int r = Integer.parseInt(br.readLine());
			freq[r][0]++;
		}

		Arrays.sort(freq, frequency);

		ArrayList<Integer> first = new ArrayList<Integer>();
		ArrayList<Integer> second = new ArrayList<Integer>();

		// Add the highest and second highest values to a list
		int i = 1000;
		while (freq[i][0] == freq[1000][0])
		{
			first.add(freq[i][1]);
			i--;
		}

		int k = i;
		while (k >= 0 && freq[k][0] == freq[i][0])
		{
			second.add(freq[k][1]);
			k--;
		}

		if (first.size() > 1)
		{
			Collections.sort(first);
			System.out.println(first.get(first.size() - 1) - first.get(0));
		}
		else
		{
			Collections.sort(second);
			System.out.println(Math.max(Math.abs(first.get(0) - second.get(0)),
					Math.abs(first.get(0) - second.get(second.size() - 1))));
		}
	}
}
