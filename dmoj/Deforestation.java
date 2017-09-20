package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Deforestation
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int l = Integer.parseInt(br.readLine());

		int[] mass = new int[l];
		
		mass[0] = Integer.parseInt(br.readLine());
		
		for (int i = 1; i < l; i++)
			mass[i] = Integer.parseInt(br.readLine()) + mass[i - 1];
		
		int q = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < q; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			if (a > 0)
				System.out.println(mass[b] - mass[a - 1]);
			else
				System.out.println(mass[b]);
		}
	}

}
