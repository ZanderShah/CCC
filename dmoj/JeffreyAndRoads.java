package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JeffreyAndRoads
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());

		double m1 = (y2 - y1) * 1.0 / (x2 - x1);
		double b1 = y1 - x1 * m1;

		int n = Integer.parseInt(br.readLine());

		int min = 0;

		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int be = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			double x = - 1.0 * c / a;
			
			if (be != 0)
			{
				double m2 = -1.0 * a / be;
				double b2 = -1.0 * c / be;

				x = (b1 - b2) / (m2 - m1);
				double y = m1 * x + b1;
			}
				if (x > Math.min(x1, x2) && x < Math.max(x1, x2))
					min++;
		}

		System.out.println(min);
	}

}
