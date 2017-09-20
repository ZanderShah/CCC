package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;


public class Sandwich
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		String s = br.readLine();
		
		LinkedList<Integer> a = new LinkedList<Integer>();
		
		for (int i = 0; i < s.length(); i++)
		{
			if (s.charAt(i) == '0')
				a.add(i + 1);
			else
				a.add(0, i + 1);
		}

		for (int i : a)
			System.out.println(i);
	}

}
