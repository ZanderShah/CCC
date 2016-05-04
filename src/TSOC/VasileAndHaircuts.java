package TSOC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class VasileAndHaircuts
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		for (int c = 0; c < n; c++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int l = Integer.parseInt(st.nextToken());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int f = Integer.parseInt(st.nextToken());
			
			if (l - a >= f && l - b <= f)
				System.out.println("Yes");
			else
				System.out.println("No");
		}

	}

}
