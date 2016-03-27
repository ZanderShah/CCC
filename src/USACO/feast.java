package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class feast
{

	public static void main(String[] args) throws Exception
	{
		// BufferedReader br = new BufferedReader(new
		// InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("feast.in"));
		PrintWriter out = new PrintWriter(new FileWriter("feast.out"));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int full = Integer.parseInt(st.nextToken());
		int orange = Integer.parseInt(st.nextToken());
		int lemon = Integer.parseInt(st.nextToken());

		int increment = (int) Math.ceil(lemon * 1.0 / orange);
		int max = full / orange * orange;
		int cur = full / orange * orange;
		int half = 0;

		for (int t = 0; t <= 1; t++)
			for (int i = 0; i <= full / lemon && max != full; i++)
			{
				cur = Math.max(max - increment * orange * i, 0) + lemon * i;

				if (cur > max && cur <= full)
					max = cur;

				cur /= 2;

				half = (full - cur) / orange * orange;

				if (half + cur > max && half + cur <= full)
					max = half + cur;

				for (int j = 0; j <= (full - cur) / lemon; j++)
				{
					half = Math.max(half - increment * orange * j, 0) + lemon
							* j;

					if (half + cur > max && half + cur <= full)
						max = half + cur;
				}
			}

		out.println(max);
		out.close();
	}
}
