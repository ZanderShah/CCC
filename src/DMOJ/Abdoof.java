package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Abdoof
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String m = br.readLine().toLowerCase();
		String[] s = new String[100];
		Arrays.fill(s, "");

		int j = 0;

		char a;
		char b = 'X';
		boolean bad = false;
		
		for (int i = 0; i < m.length(); i++)
		{
			b = 'X';
			
			a = m.charAt(i);

			if (i + 1 < m.length())
				b = m.charAt(i + 1);

			if (a == ' ')
				j++;
			else if (a == 'c' && b == 'h')
			{
				s[j] += 'A';
				i++;
			}
			else if (a == 'b' && b == 'd')
			{
				s[j] += 'A';
				i++;
			}
			else if (a == 'o' && b == 'o')
			{
				s[j] += 'B';
				i++;
			}
			else if (a == 't' || a == 'm' || a == 'd' || a == 'b' || a == 'r')
				s[j] += 'A';
			else if (a == 'a' || a == 'e' || a == 'i')
				s[j] += 'B';
			else if (a == 'n' || a == 'v' || a == 'f')
				s[j] += 'C';
			else
				bad = true;

			b = 'X';
		}

		for (int i = 0; i <= j; i++)
			if (s[i].length() < 1)
				bad = true;
		
		if (j == 0 || bad == true)
			System.out.println("invalid");
		else
		{
			bad = false;

			for (int w = 0; w <= j && !bad; w++)
			{
				char p = 'X';
				
				for (int i = 0; i < s[w].length() && !bad; i++)
				{
					char c = s[w].charAt(i);

					if (i == 0 && c != 'A' && c != 'B')
						bad = true;

					if (i == s[w].length() - 1 && c != 'C' && c != 'A')
						bad = true;

					if (c == 'C' && i < s[w].length() - 1)
						bad = true;

					if (c == p)
						bad = true;

					p = c;
				}
			}

			if (bad)
				System.out.println("invalid");
			else
				System.out.println("valid");
		}
	}

}
