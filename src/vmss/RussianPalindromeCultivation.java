package vmss;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class RussianPalindromeCultivation
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String n = br.readLine();
		String left, right;
		String check = "1";
		int middle;

		boolean allNine = true;

		for (int i = 0; i < n.length() && allNine; i++)
		{
			if (n.charAt(i) - '0' != 9)
				allNine = false;
			
			if (i != 0)
				check += "0";
		}
		
		if (allNine)
			System.out.println(check + "1");
		else
		{
			if (n.length() % 2 == 1)
			{
				left = n.substring(0, n.length() / 2);
				middle = n.charAt(n.length() / 2) - '0';
			}
			else
			{
				left = n.substring(0, n.length() / 2 - 1);
				middle = (n.charAt(n.length() / 2 - 1) - '0') * 10
						+ (n.charAt(n.length() / 2) - '0');
			}

			right = n.substring(n.length() / 2 + 1);

			if (right.compareTo(new StringBuilder(left).reverse().toString()) >= 0)
			{
				if (middle < 10)
					middle++;
				else if (middle % 10 == middle / 10)
					middle += 11;
				else if (middle % 10 > middle / 10)
					middle += 10;
				else
					middle++;
			}

			if (n.length() % 2 == 0 && (middle % 10 != middle / 10))
			{
				if (middle / 10 > middle % 10)
					middle += middle / 10 - middle % 10;
				else
					middle += 10 + (middle + 10) / 10 - middle % 10;
			}

			System.out.println(left + middle
					+ new StringBuilder(left).reverse());
		}
	}
}
