package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class cardgame
{

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("cardgame.in"));
		PrintWriter out = new PrintWriter(new FileWriter("cardgame.out"));

		int n = Integer.parseInt(br.readLine());
		int[] b = new int[n * 2];

		for (int i = 0; i < n / 2; i++)
			b[Integer.parseInt(br.readLine()) - 1] = 1;
		
		for (int i = 0; i < n / 2; i++)
			b[Integer.parseInt(br.readLine()) - 1] = 2;

		int[] v = b.clone();

		int w = 0;

		for (int i = n * 2 - 1; i >= 0; i--)
			if (v[i] == 0)
			{
				int k = i;

				while (k > 0 && b[k] != 1)
					k--;

				if (b[k] == 1)
				{
					b[k] = 0;
					v[i] = 1;
					w++;
				}
			}
		
		for (int i = 0; i < 2 * n; i++)
			if (v[i] == 0)
			{
				int k = i;

				while (k < 2 * n - 1 && b[k] != 2)
					k++;

				if (b[k] == 2)
				{
					b[k] = 0;
					w++;
				}
			}
		
		out.println(w);
		out.close();

	}

}
