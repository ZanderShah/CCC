package tsoc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class YouAndCrossroads
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int q = Integer.parseInt(br.readLine());
		int[] gold = new int[5];
		
		for (int i = 0; i < 2 * q; i++)
		{
			String s = br.readLine();
			for (int j = 0; j < 2 * q; j++)
				if (s.charAt(j) == 'g')
					if (j < q && i < q)
						gold[2]++;
					else if (j < q)
						gold[3]++;
					else if (i < q)
						gold[1]++;
					else 
						gold[4]++;
	
		}
		
		int max = 0;
		for (int i = 1; i < 5; i++)
		{
			if (gold[i] > gold[max])
				max = i;
		}
		
		System.out.println(max);

	}

}
