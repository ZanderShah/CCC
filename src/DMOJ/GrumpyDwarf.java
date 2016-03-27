package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class GrumpyDwarf
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int steelBars = Integer.parseInt(br.readLine());
		int convert = Integer.parseInt(br.readLine());
		int total = 0;
		int swords = 0;

		while (steelBars != 0)
		{
			total += steelBars;
			swords += steelBars;

			steelBars = swords / convert;

			swords -= steelBars * convert;
		}
		System.out.println(total);
	}
}
