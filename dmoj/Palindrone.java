package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Palindrone
{

	public static void main(String[] args) throws Exception
	{

		BufferedReader br = new BufferedReader(new
				InputStreamReader(System.in));

		String s = br.readLine();
		long n = 100000;

		if (s.length() < 6)
			n = Integer.parseInt(s);

		long t = 0;

		for (long i = 1; i <= n; i++)
		{
			long p = i;
			if (p % 2 == 1)
				p++;

			t = (long) (t + 9 * Math.min(Math.pow(10, p / 2 - 1),
					1000000000)) % 1000000000;
		}

		System.out.println(t % 1000000000);
	}
}
