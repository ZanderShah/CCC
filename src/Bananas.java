import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bananas
{
	public static boolean isMonkey(String s)
	{
		// Replaces monkey words with a smaller monkey word which
		// will eventually reduce the problem to a simple state
		for (int i = 0; i < s.length() - 2; i++)
		{
			String c = s.substring(i, i + 3);
			
			if (c.equals("ANA") || c.equals("BAS"))
			{
				s = s.substring(0, i) + "A" + s.substring(i + 3);
				i = -1;
			}
		}
		
		return s.equals("A");
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine();
		
		while (!s.equals("X"))
		{
			if (isMonkey(s))
				System.out.println("YES");
			else
				System.out.println("NO");
			
			s = br.readLine();
		}
	}
}
