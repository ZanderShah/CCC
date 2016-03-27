package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class GenevaConfection
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int cases = Integer.parseInt(br.readLine());

		// Tries to put the sequence in order by storing whatever is
		// not in order in a stack
		for (int test = 0; test < cases; test++)
		{
			int n = Integer.parseInt(br.readLine());
			int[] c = new int[n];
			
			for (int i = 0; i < n; i++)
				c[n - 1 - i] = Integer.parseInt(br.readLine());
			
			Stack<Integer> b = new Stack<Integer>();

			int tar = 1;

			for (int i = 0; i < n; i++)
			{
				int a = c[i];
				
				if (a == tar)
					tar++;
				else
				{
					b.push(a);
				}
				
				while (!b.isEmpty() && b.peek().equals(tar))
				{
					b.pop();
					tar++;
				}
			}	

			if (b.isEmpty())
				System.out.println("Y");
			else
				System.out.println("N");
		}
	}
}
