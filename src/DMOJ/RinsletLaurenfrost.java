package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class RinsletLaurenfrost
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] a = new int[26];
		int[] b = new int[26];
		
		String s = br.readLine();
		for (int i = 0; i < s.length(); i++)
			a[s.charAt(i) - 'a']++;
		s = br.readLine();
		for (int i = 0; i < s.length(); i++)
			b[s.charAt(i) - 'a']++;
		
		int c = 0;
		for (int i = 0; i < 26; i++)
			c += Math.abs(a[i] - b[i]);
		System.out.println(c);
	}

}
