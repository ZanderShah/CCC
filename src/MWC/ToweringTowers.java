package MWC;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ToweringTowers
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(
				System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));

		int n = Integer.parseInt(br.readLine());

		int[] heights = new int[1001];
		int lastH = 0;
		int topH = 0;

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0, h, closest; i < n; i++)
		{
			h = Integer.parseInt(st.nextToken());
			heights[h] = i;

			if (h < lastH)
				out.print(1 + " ");
			else if (h >= topH)
			{
				out.print(i + " ");
				topH = h;
			}
			else
			{
				closest = 0;
				for (int j = h + 1; j < 1001; j++)
					closest = Math.max(closest, heights[j]);
				out.print(i - closest + " ");
			}

			lastH = h;
		}

		out.close();
	}
}