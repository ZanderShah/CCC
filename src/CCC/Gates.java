package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Gates
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int g = Integer.parseInt(br.readLine());
		int n = Integer.parseInt(br.readLine());
		
		// Adds all possible gates to a list
		ArrayList<Integer> t = new ArrayList<Integer>();
		
		for (int i = 1; i <= g; i++)
			t.add(i);

		long total = 0;
		
		// Binary searches for the best possible gate for a given plane
		// If a gate cannot be found, the plan has nowhere to land
		for (int i = 0; i < n; i++)
		{
			int q = Integer.parseInt(br.readLine());
			int p = Math.abs(Collections.binarySearch(t, q) + 1);

			if (p == t.size())
				p--;
			
			if (p >= 0 && t.get(p) > q)
				p--;

			if (p >= 0)
			{
				t.remove(p);
				total++;
			}
			else
				break;
		}

		System.out.println(total);
	}
}
