package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class highcard
{

	public static void main(String[] args) throws Exception
	{
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("highcard.in"));
		PrintWriter out = new PrintWriter(new FileWriter("highcard.out"));

		int n = Integer.parseInt(br.readLine());
		boolean[] b = new boolean[n * 2];

		for (int i = 0; i < n; i++)
			b[Integer.parseInt(br.readLine()) - 1] = true;

		boolean[] v = b.clone();
		
		int w = 0;

		for (int i = n * 2 - 1; i >= 0; i--)
			if (!v[i])
			{
				int k = i;

				while (k > 0 && !b[k])
					k--;

				if (b[k])
				{
					b[k] = false;
					w++;
				}
			}

		out.println(w);
		out.close();
	}

}
