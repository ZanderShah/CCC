package CCO;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class HungryFox
{
	public static long taste, w;

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		w = Long.parseLong(st.nextToken());

		ArrayList<Long> max = new ArrayList<Long>();
		for (int i = 0; i < n; i++) 
			max.add(Long.parseLong(br.readLine()));
		
		Collections.sort(max);

		// Minimum Taste can be obtained by eating all the crackers in order
		if (max.get(0) > w)
			System.out.print(max.get(max.size() - 1) - w + " ");
		else if (max.get(max.size() - 1) < w)	
			System.out.print(w - max.get(0) + " ");
		else
			System.out.print(max.get(max.size() - 1) - max.get(0) + " ");
		
		// Maximum Taste can be obtained by maximizing the amount of jumps you make 
		// across the staring point
		max.add(w);
		Collections.sort(max);
		int i = Collections.binarySearch(max, w);
		max.remove(i);
		
		if ((i + 1) * 1.0 / (n + 2) == 0.5)
		{
			if (Math.abs(w - max.get(0)) > Math.abs(w - max.get(max.size() - 1)))
				i = 0;
			else
				i = max.size() - 1;
		}
		else if ((i + 1) * 1.0 / (n + 1) > 0.5)
			i = 0;
		else
			i = max.size() - 1;
		
		taste = 0;
		long temp = w;
		while (!max.isEmpty())
		{
			taste += Math.max(Math.abs(temp - max.get(i)),
					Math.abs(w - max.get(i)));
			temp = max.get(i);
			max.remove(i);

			if (i == 0)
				i = max.size() - 1;
			else
				i = 0;
		}

		System.out.print(taste);

	}
}
