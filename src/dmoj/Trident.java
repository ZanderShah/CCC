package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Trident
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int s = Integer.parseInt(br.readLine());
		int h = Integer.parseInt(br.readLine());
		
		String sp = "";
		for (int i = 0; i < s; i++)
		{
			sp += " ";
		}
		
		for (int i = 0; i < t; i++)
			System.out.printf("*%s*%s*%n", sp, sp);
		
		for (int i = 0; i < 3 + 2 * s; i++)
			System.out.print("*");
		
		System.out.println();
		sp += " ";
		
		for (int i = 0; i < h; i++)
			System.out.printf("%s*%n", sp);

	}

}
