package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class G
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[][] g = { { 'G', 'G', 'G', 'G', 'G' },
				{ 'G', '.', '.', '.', '.' },
				{ 'G', '.', '.', 'G', 'G' },
				{ 'G', '.', '.', '.', 'G' },
				{ 'G', 'G', 'G', 'G', 'G' } };

		int n = Integer.parseInt(br.readLine());

		for (int i = 0; i < 5; i++)
			for (int q = 0; q < n; q++)
			{		
				for (int j = 0; j < 5; j++)
					for (int r = 0; r < n; r++)
						System.out.print(g[i][j]);
				System.out.println();
			}

	}
}
