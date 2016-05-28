package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class RabbitGirls
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());

		if (n < k)
			System.out.println(k - n);
		else
		{
			n %= k;

			System.out.println(Math.min(n, k - n));
		}
	}

}
