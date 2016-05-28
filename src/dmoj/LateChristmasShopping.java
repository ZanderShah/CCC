package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class LateChristmasShopping
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] presents = new int[10];
		
		boolean repeat = false;

		for (int i = 0; i < n && !repeat; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();

			while (st.hasMoreTokens() && !repeat)
			{
				int p = Integer.parseInt(st.nextToken()) - 1;
				if (presents[p] < i + 1 && presents[p] != 0)
					repeat = true;
				else
					presents[p] = i + 1;
			}
		}

		if (repeat)
			System.out.println("YES");
		else
			System.out.println("NO");

	}

}
