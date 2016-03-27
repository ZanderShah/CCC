package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Dictionary
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		String[] d = new String[n];

		for (int i = 0; i < n; i++)
			d[i] = br.readLine();

		Arrays.sort(d);

		for (int i = 0; i < n; i++)
		{
			if (i != 0 && d[i - 1].charAt(0) == d[i].charAt(0))
				System.out.print(", " + d[i]);
			else
			{
				if (i != 0)
					System.out.println();
				System.out.print(d[i]);
			}
		}
	}

}
