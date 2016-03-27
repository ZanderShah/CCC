package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Substrings
{
	static int LCP(String a, String b)
	{
		for (int i = 0; i < Math.min(a.length(), b.length()); i++)
			if (a.charAt(i) != b.charAt(i))
				return i;
		return Math.min(a.length(), b.length());
	}
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int cases = Integer.parseInt(br.readLine());
		
		for (int c = 0; c < cases; c++)
		{
			String s = br.readLine();
			String[] prefix = new String[s.length()];
			for (int i = 0; i < s.length(); i++)
				prefix[i] = s.substring(i);
			Arrays.sort(prefix);
			
			int total = prefix[0].length() + 1;
			for (int i = 1; i < s.length(); i++)
				total += prefix[i].length() - LCP(prefix[i], prefix[i - 1]);
			
			System.out.println(total);
		}
	}
}
