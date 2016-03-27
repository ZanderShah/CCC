package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class MultipleStatements
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] a = new int[n + 1];
	
		for (int i = 0; i < n; i++)
		{
			int t = Integer.parseInt(br.readLine());

			if (t <= n)
			{
				a[t]++;
			}
		}

		boolean isParadox = true;

		for (int i = n; i >= 0; i--)
		{
			if (a[i] == i)
			{
				System.out.println(i);
				isParadox = false;
				break;
			}
		}

		if (isParadox)
			System.out.println("Paradox!");
	}

}
