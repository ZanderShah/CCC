package ccc;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class AliceThroughTheLookingGlass
{
	static int crystal(int c, int x)
	{
		if (c == 0)
			return 0;
		int m = (int) Math.pow(5, c - 1);
		int a = x / m;
		if (a == 1 || a == 3)
			return m + crystal(c - 1, x % m);
		else if (a == 2)
			return 2 * m + crystal(c - 1, x % m);
		return 0;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int test = Integer.parseInt(br.readLine());

		for (int t = 0; t < test; t++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());

			if (y < crystal(m , x))
				System.out.println("crystal");
			else
				System.out.println("empty");
		}
	}

}
