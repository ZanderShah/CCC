package WCIPEG;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class CrossCountry
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s = br.readLine();
		
		if (s.equals("MG"))
			System.out.println("midget girls");
		else if (s.equals("MB"))
			System.out.println("midget boys");
		else if (s.equals("JG"))
			System.out.println("junior girls");
		else if (s.equals("JB"))
			System.out.println("junior boys");
		else if (s.equals("SG"))
			System.out.println("senior girls");
		else if (s.equals("SB"))
			System.out.println("senior boys");
		else
			System.out.println("invalid code");
	}

}
