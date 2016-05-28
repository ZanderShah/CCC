package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TheBigClock
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int h = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int n = Integer.parseInt(br.readLine());

		m += n % 60;

		if (m >= 60)
		{
			int t = m / 60;
			h += t;
			m -= t * 60;
		}

		h = (h + n / 60) % 24;

		System.out.println(h + " " + m);
	}
}
