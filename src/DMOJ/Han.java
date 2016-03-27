package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Han
{
	static int[] a;
	static int last = 0;
	static int lastChar = -1;

	static void add(int n, boolean r)
	{
		int t = n % 26;
		for (int i = 0; i < 26; i++)
			a[i] += n / 26;
		
		if (r)
			for (int i = 1; i <= t; i++)
				a[(i + lastChar) % 26]++;
		else
			for(int i = 1; i <= t; i++)
				a[(lastChar - i + 26) % 26]++;

		last += n;
		if (r)
			lastChar = (lastChar + n) % 26;
		else
			lastChar = (lastChar - n + 101562500) % 26;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int q = Integer.parseInt(br.readLine());

		a = new int[26];
		boolean right = true;

		for (int i = 0; i < q; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			String command = st.nextToken();
			int n = Integer.parseInt(st.nextToken());
			
			add(n - last, right);

			if (command.equals("UPIT"))
			{
				char c = st.nextToken().charAt(0);
				System.out.println(a[c - 'a']);
			}
			else if (right)
				right = false;
			else
				right = true;
		}
	}

}
