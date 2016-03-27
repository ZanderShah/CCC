package Codeforces;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class WetSharkOddEven
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		long m = Integer.MAX_VALUE;
		long s = 0;
		
		for (int i = 0; i < n; i++)
		{
			long v = Long.parseLong(st.nextToken());
			if (v % 2 == 1 && v < m)
				m = v;
			s += v;
		}
		
		if (s % 2 == 0)
			System.out.println(s);
		else
			System.out.println(s - m);
	}

}
