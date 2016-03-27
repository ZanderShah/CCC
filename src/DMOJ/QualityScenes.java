package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class QualityScenes
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		double a = Double.parseDouble(br.readLine());
		double b = Double.parseDouble(br.readLine());
		
		double c = Double.parseDouble(br.readLine());
		double d = Double.parseDouble(br.readLine());
		
		if (b > c && d > a)
			System.out.println("YES");
		else if (a > d && b > c)
			System.out.println("YES");
		else if (a == c || b == d)
			System.out.println("YES");
		else if (a <= c && b >= d)
			System.out.println("YES");
		else if (c <= a && d >= b)
			System.out.println("YES");
		else
			System.out.println("NO");
	}

}
