package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class ItamiAndManga
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		String[] s = new String[n];
		double[] d = new double[n];
		
		int max = 0;
		
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			s[i] = st.nextToken();
			d[i] = Double.parseDouble(st.nextToken());
			
			if (d[i] > d[max])
				max = i;
		}
		
		System.out.println(s[max]);
		
		
	}

}
