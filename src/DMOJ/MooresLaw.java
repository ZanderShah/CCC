package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MooresLaw
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		double c = Double.parseDouble(br.readLine());

		int n = (int) Math.ceil(730 * Math.log(c) / Math.log(2) - 730);

		int y = n / 365;
		n -= y * 365;

		int m = n / 30;
		n -= m * 30;

		int w = n / 7;
		n -= w * 7;

		if (y == 0 && m == 0 && w == 0 && n == 0)
			System.out.print("Now!");
		else
		{
			String s = "";
			if (y != 0)
				s += (y + "Y");
			if (m != 0)
				s += (" " + m + "M");
			if (w != 0)
				s += (" " + w + "W");
			if (n != 0)
				s += (" " + n + "D");
			
			System.out.println(s.trim());
		}
	}
}
