package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class UnevenSand
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("1000000000");
		System.out.flush();
		String s = br.readLine();
		
		long l = 0;
		long h = 2000000001;
		
		while(!s.equals("OK"))
		{
			if (s.equals("FLOATS"))
				h = (h + l) / 2;
			else
				l = (h + l) / 2;
			System.out.println((h + l) / 2);
			System.out.flush();
			s = br.readLine();
		}

	}

}
