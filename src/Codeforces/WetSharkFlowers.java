package Codeforces;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WetSharkFlowers
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		double[] v = new double[n];
		double per = 0;
		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			int c = (b - (int) Math.ceil((a * 1.0) / p) * p + p) / p;

			v[i] = (c * 1.0) / (b - a + 1);
			
			if (i != 0)
				per += v[i] + v[i - 1] - v[i] * v[i - 1];
		}

		per += v[0] + v[n - 1] - v[0] * v[n - 1];

		System.out.println(per * 2000);
	}

}
