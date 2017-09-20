package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CheesecakeDistribution
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		long[] f = new long[n];
		long t = 0;

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < n; i++)
		{
			f[i] = Long.parseLong(st.nextToken());
			t += f[i];
		}

		if (t % n != 0)
			System.out.println("Impossible");
		else
		{
			long m = 0;
			
			for (int i = 0; i < n; i++)
				if (f[i] > t / n)
					m += (f[i] - t / n);
			
			System.out.println(m);
		}
	}
}
