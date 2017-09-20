package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.stream.IntStream;


public class GloballyUniqueShells
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		
		HashMap<Integer, Integer> s = new HashMap<Integer, Integer>();
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < a; i++)
			s.put(Integer.parseInt(st.nextToken()), i);
		
		int c = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < b; i++)
			if (s.containsKey(Integer.parseInt(st.nextToken())))
				c++;
		
		System.out.println(n - c);
		
	}

}
