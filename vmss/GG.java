package vmss;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class GG
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String g = br.readLine();
		
		int[] p = new int[g.length()];
		for (int i = 0; i < g.length(); i++)
		{
			if (g.charAt(i) == 'G')
				p[i] = 1;
			if (i != 0)
				p[i] += p[i - 1];
		}
		
		
		int q = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < q; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			if (a == 0)
				System.out.println(p[b]);
			else
				System.out.println(p[b] - p[a - 1]);
		}

	}

}
