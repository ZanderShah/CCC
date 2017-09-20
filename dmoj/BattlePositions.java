package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class BattlePositions
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int k = Integer.parseInt(br.readLine());
		int j = Integer.parseInt(br.readLine());
		
		int[] s = new int[n + 1];
		
		for (int i = 0; i < j; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken());
			s[a] += c;
			s[b + 1] -= c;
		}
		
		int t = 0;
		int r = 0;
		for (int i = 0; i < n; i++)
		{
			r += s[i];
			if (r < k)
				t++;
		}

		System.out.println(t);
	}

}
