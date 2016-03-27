package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

/*
 * This still times out for some test cases since adding the element to the list
 * is not fast enoguh
 */
public class PinballRanking
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		ArrayList<Integer> r = new ArrayList<Integer>();

		int t = 0;
		
		// Binary search to determine the insertion spot
		for (int i = 1; i <= n; i++)
		{
			int s = Integer.parseInt(br.readLine());
			int k = Math.abs(Collections.binarySearch(r, s) + 1);

			r.add(k, s);
			
			t += i - k;
		}
		
		double a = Math.round((t * 1.0 / n) * 100) / 100.0;
		System.out.printf("%.2f", a);
	}
	
}