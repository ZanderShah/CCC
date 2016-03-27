package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class DaysOfChristmas
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		String before = "On the ";
		String after = " day of Christmas my true love sent to me:";
		String[] gifts = new String[n + 1];

		for (int i = 1; i <= n; i++)
		{
			gifts[i] = i + " " + br.readLine();

			if (i % 10 == 1 && i % 100 != 11)
				System.out.println(before + i + "st" + after);
			else if (i % 10 == 2 && i % 100 != 12)
				System.out.println(before + i + "nd" + after);
			else if (i % 10 == 3 && i % 100 != 13)
				System.out.println(before + i + "rd" + after);
			else
				System.out.println(before + i + "th" + after);
			for (int j = i; j >= 1; j--)
			{
				if (i != 1 && j == 1)
					System.out.println("and " + gifts[j]);
				else
					System.out.println(gifts[j]);
			}

			System.out.println();
		}

	}

}
