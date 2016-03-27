package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ItamiAndCipher
{
	static String cipher(String msg, int shift)
	{
		String s = "";
		int len = msg.length();
		for (int x = 0; x < len; x++)
		{
			char c = (char) (msg.charAt(x) + shift);
			if (c > 'z')
				s += (char) (msg.charAt(x) - (26 - shift));
			else
				s += (char) (msg.charAt(x) + shift);
		}
		return s;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String code = br.readLine();
		String key = br.readLine();

		for (int i = 0; i < 26; i++)
		{
			String t = cipher(key, i);
			if (code.indexOf(t) != -1)
			{
				System.out.println(i);
				System.out.println(cipher(code,26-i));
				break;
			}
		}
	}

}
