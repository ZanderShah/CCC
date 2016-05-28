package wcipeg;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Direction
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < t; i++)
		{
			int d = Integer.parseInt(br.readLine());
			
			if (d < 46)
				System.out.println("N");
			else if (d < 136)
				System.out.println("E");
			else if (d < 226)
				System.out.println("S");
			else if (d < 316)
				System.out.println("W");
			else
				System.out.println("N");
		}
	}

}
