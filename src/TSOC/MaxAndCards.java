package TSOC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class MaxAndCards
{
	public static long factorial(int i)
	{
		long f = 1;
		for (int j = 2; j <= i; j++)
			f *= j;
		return f;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int q = Integer.parseInt(br.readLine());

		ArrayList<Integer> refill = new ArrayList<Integer>();
		for (int i = 1; i <= n; i++)
			refill.add(i);
		
		for (int query = 0; query < q; query++)
		{
			ArrayList<Integer> left = new ArrayList<Integer>(refill);
			
			Long p = Long.parseLong(br.readLine());

			while (left.size() > 1)
			{
				int d = (int) Math.floor(p * 1.0 / factorial(left.size() - 1));
				System.out.print(left.get(d) + " ");
				left.remove(left.indexOf(left.get(d)));
				p %= factorial(left.size());
			}
			System.out.print(left.get(0));
			System.out.println();
		}

	}

}
