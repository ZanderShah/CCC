package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Sawmill
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Integer[] e = new Integer[n];
		Integer[] s = new Integer[n];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringTokenizer sr = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < n; i++)
		{
			e[i] = Integer.parseInt(st.nextToken());
			s[i] = Integer.parseInt(sr.nextToken());
		}
		
		Arrays.sort(e);
		Arrays.sort(s);
		
		long total = 0;

		for (int i = 0; i < n; i++)
			total += e[i] * s[n - 1 - i];
		
		System.out.println(total);
	}

}
