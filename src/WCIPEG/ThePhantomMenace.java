package WCIPEG;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ThePhantomMenace
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] scenes = new int[n];

		for (int i = 0; i < n; i++)
			scenes[i] = Integer.parseInt(st.nextToken());

		if (scenes[n - 1] == 0)
			for (int i = 1; i <= 4; i++)
				if (scenes[n - 1 - i] != i)
				{
					scenes[n - 1] = i;
					break;
				}
		
		if (scenes[0] == 0)
			for (int i = 1; i <= 4; i++)
				if (scenes[i] != i)
				{
					scenes[0] = i;
					break;
				}

		for (int i = 1; i < n - 1; i++)
			if (scenes[i] == 0)
				for (int j = 1; j <= 4; j++)
					if (scenes[i - 1] != j && scenes[i + 1] != j)
					{
						scenes[i] = j;
						break;
					}
		
		for (int i = 0; i < n; i++)
			System.out.print(scenes[i]);
	}

}
