package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class PersonalAssistant
{
	public static int next(long[][] t, int i)
	{
		int k = Arrays.binarySearch(t[0], t[1][i]);

		if (k < 0)
			return -k - 1;
		
		while(t[0][k] == t[0][k - 1])
			k--;
		
		return k;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long[][] t = new long[3][n];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());

			t[0][i] = Long.parseLong(st.nextToken());
			t[1][i] = Long.parseLong(st.nextToken()) + t[0][i];
			t[2][i] = Long.parseLong(st.nextToken());
		}

		long[] joy = new long[n];
		joy[n - 1] = t[2][n - 1];

		for (int i = n - 2; i >= 0; i--)
			if (t[0][i + 1] >= t[1][i])
				joy[i] = joy[i + 1] + t[2][i];
			else if (next(t,i) <= n - 1)
				joy[i] = Math.max(joy[i + 1], joy[next(t, i)] + t[2][i]);
			else
				joy[i] = Math.max(joy[i + 1], t[2][i]);

		System.out.println(joy[0]);
	}
}