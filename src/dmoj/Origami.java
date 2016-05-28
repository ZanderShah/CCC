package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Origami
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long n = Long.parseLong(st.nextToken());
		long k = Long.parseLong(st.nextToken());

		long total = 1;
		long cut = 0;
		long current = 0;

		if (n < 1000000)
		{
			while (total < n)
			{
				current += Math.min(total, k);
				total -= current;

				current *= 2;
				cut++;

				total += current;
				current = 0;
			}
		}
		else
		{
			while (total < k)
			{
				current += Math.min(total, k);
				total -= current;

				current *= 2;
				cut++;

				total += current;
				current = 0;
			}

			cut += (long) Math.ceil((n - total) * 1.0 / k);
		}

		System.out.println(cut);
	}

}
