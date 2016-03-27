package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DMails
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String okabe = "elpsycongroo";
		String mayuri = "tuturu";
		String daru = "superhacker";
		String kurisu = "myfork";

		int n = Integer.parseInt(br.readLine());

		for (int i = 0, o, m, d, k; i < n; i++)
		{
			String s = br.readLine();
			o = 0;
			m = 0;
			d = 0;
			k = 0;
			for (int j = 0; j < s.length(); j++)
			{
				char c = s.charAt(j);
				if (o < okabe.length() && c == okabe.charAt(o))
					o++;
				if (m < mayuri.length() && c == mayuri.charAt(m))
					m++;
				if (d < daru.length() && c == daru.charAt(d))
					d++;
				if (k < kurisu.length() && c == kurisu.charAt(k))
					k++;
			}

			boolean multiple = false;
			if (o == okabe.length())
			{
				System.out.print("Okabe");
				multiple = true;
			}
			if (m == mayuri.length())
				if (multiple)
					System.out.print(" or Mayuri");
				else
				{
					System.out.print("Mayuri");
					multiple = true;
				}
			if (d == daru.length())
				if (multiple)
					System.out.print(" or Daru");
				else
				{
					System.out.print("Daru");
					multiple = true;
				}
			if (k == kurisu.length())
				if (multiple)
					System.out.print(" or Kurisu");
				else
				{
					System.out.print("Kurisu");
					multiple = true;
				}

			if (!multiple)
				System.out.println("SERN spy!");
			System.out.println();
		}
	}

}
