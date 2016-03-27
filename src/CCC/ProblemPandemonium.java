package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class ProblemPandemonium
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[] diff = new int[100000];
		
		int max = -1;
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
		{
			int a = Integer.parseInt(st.nextToken()) - 1;
			
			diff[a]++;
		
			if (diff[a] > max)
				max = diff[a];
		}
		
		System.out.println(max);

	}

}
