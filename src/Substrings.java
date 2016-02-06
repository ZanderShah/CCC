import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeMap;


public class Substrings
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int cases = Integer.parseInt(br.readLine());
		
		for (int c = 0; c < cases; c++)
		{
			String s = br.readLine();
			int total = 1;
			
			for (int i = 0; i < s.length(); i++)
			{
				TreeMap<String, Integer> sub = new TreeMap<String, Integer>();
				for (int j = 0; j < s.length() - i; j++)
					if (!sub.containsKey(s.substring(j, j + 1 + i)))
						sub.put(s.substring(j, j + 1 + i), j);
				total += sub.size();
			} 
			
			System.out.println(total);
		}
	}
}
