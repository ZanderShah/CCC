package DMOJ;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ShoelaceFormula
{

	public static void main(String[] args) throws NumberFormatException,
			IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] points = new int[n][2];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			points[i][0] = Integer.parseInt(st.nextToken());
			points[i][1] = Integer.parseInt(st.nextToken());
		}

		int area = 0;

		for (int i = 0; i < n; i++)
		{
			int j = (i + 1) % n;
			area += (points[i][0] * points[j][1] - points[j][0] * points[i][1]);
		}

		System.out.println((int) Math.ceil(Math.abs(area) * 1.0 / 2));
	}

}
