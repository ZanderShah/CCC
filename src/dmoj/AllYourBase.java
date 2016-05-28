package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AllYourBase
{
	static int baseOne(String x)
	{
		int c = 0;
		for (int i = 0; i < x.length(); i++)
			if (x.charAt(i) == '1')
				c++;
		return c;
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int e = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());

		int[] base = new int[n + 1];
		base[0] = e;
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= n; i++)
			base[i] = Integer.parseInt(st.nextToken());

		int b = base[n];
		boolean one = false;
		for (int i = n - 1; i >= 0 && !one; i--)
			if (b != 1)
				b = Integer.parseInt(base[i] + "", b);
			else
				b = baseOne(String.valueOf(base[i]));

		if (!one)
			System.out.println(b);
	}
}
