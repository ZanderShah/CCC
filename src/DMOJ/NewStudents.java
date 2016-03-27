package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class NewStudents
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int i = Integer.parseInt(br.readLine());
		int t = 0;
		for (int j = 0; j < i; j++)
			t += Integer.parseInt(br.readLine());
		
		double a = t * 1.0 / i;
		
		int s = Integer.parseInt(br.readLine());
		
		for (int j = 0; j < s; j++)
		{
			i++;
			a = a * (i - 1) / i + Integer.parseInt(br.readLine()) * 1.0 / i;
			System.out.println(a);
		}

	}

}
