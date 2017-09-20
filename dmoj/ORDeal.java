package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class ORDeal
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		long n = Long.parseLong(br.readLine());
		
		long b = (long) (Math.log(n) / Math.log(2));
		
		for (long i = 0; i <= b; i++)
			System.out.print("1");
	}

}
