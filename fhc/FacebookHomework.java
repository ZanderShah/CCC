package fhc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FacebookHomework
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int[] primality = new int[(int) (Math.pow(10, 7) + 1)];
		for (int i = 2; i < primality.length; i++)
		{
			if (primality[i] == 0)
				for (int j = i; j < primality.length; j += i)
					primality[j]++;
		}
		
		int n = Integer.parseInt(br.readLine());
		for (int j = 0; j < n; j++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			
			int ans = 0;
			for (int i = a; i <= b; i++)
				if (primality[i] == k)
					ans++;
			
			System.out.println("Case #" + (j + 1) + ": " + ans);
		}
	}
}
