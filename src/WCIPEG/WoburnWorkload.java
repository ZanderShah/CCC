package WCIPEG;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WoburnWorkload
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		
		int a = Integer.parseInt(br.readLine());
		int[] m = new int[a];
		int[] t = new int[a];
				
		for (int i = 0; i < a; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			m[i] = Integer.parseInt(st.nextToken());
			t[i] = Integer.parseInt(st.nextToken());
		}
		
		int time = 0;
		int penalty = 0;
		
		for (int i = 0; i < a; i++)
		{
			time += t[i];
			
			if (m[i] < time)
			{
				penalty += time - m[i];
				time += m[i] - time;
			}
		}
		
		System.out.println(penalty);
	}
}
