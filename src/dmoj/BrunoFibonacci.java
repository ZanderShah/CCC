package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BrunoFibonacci
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		String s = br.readLine();

		int c = 1;
		int l = 1;
		
		for (int i = 1; i <= s.length(); i++)
		{
			if (s.charAt(i - 1) == 'A')
				if (i == c)
				{
					c += l;
					l = i;
				}
				else
				{
					System.out.println("Bruno, GO TO SLEEP");
					break;
				}
			else if (i == c && s.charAt(i - 1) != 'A')
			{
				System.out.println("Bruno, GO TO SLEEP");
				break;
			}
			if (i == s.length())
				System.out.println("That's quite the observation!");
		}

	}

}
