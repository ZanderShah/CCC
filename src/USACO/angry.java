package USACO;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class angry
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader br = new BufferedReader(new FileReader("angry.in"));
		PrintWriter out = new PrintWriter(new FileWriter("angry.out"));

		int n = Integer.parseInt(br.readLine());
		int[] pos = new int[n];

		for (int i = 0; i < n; i++)
			pos[i] = Integer.parseInt(br.readLine());

		Arrays.sort(pos);

		int[] minL = new int[n];
		int[] minR = new int[n];

		for (int i = 1; i < n; i++)
			minL[i] = Math.max(minL[i - 1] + 1, pos[i] - pos[i - 1]);

		for (int i = n - 2; i >= 0; i--)
			minR[i] = Math.max(minR[i + 1] + 1, pos[i + 1] - pos[i]);

		int[] diff = new int[n];

		double max = 0;
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			diff[i] = Math.min(minL[i], minR[i]) + 1;
			if (diff[i] > max)
			{
				max = diff[i];
				x = i;
			}
		}

		for (int i = Math.min(x/ 2, (n - x) / 2); i >= 0; i--)
		{
			if (pos[x] - pos[x - i] < max && pos[x + i] - pos[x] < max)
			{
				while (max - 0.1 >= diff[x - i] && max - 0.1 >= diff[x + i])
					max -= 0.1;
			}
		}

		for (int i = 1; i < n; i++)
			if (max < pos[i] - (pos[i] + pos[i - 1]) / 2.0)
				max = pos[i] - (pos[i] + pos[i - 1]) / 2.0;

		System.out.printf("%.1f", max);
		System.out.close();
	}
}
