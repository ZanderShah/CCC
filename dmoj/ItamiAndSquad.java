package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class ItamiAndSquad
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int l = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int[] soldiers = new int[n];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			soldiers[i] = Integer.parseInt(st.nextToken());
			
		Arrays.sort(soldiers);
		int total = 0;
		for (int i = n - r; i >= 0; i -=  l)
		{
			total += soldiers[i];
		}
		
		System.out.println(total);
	}
}
