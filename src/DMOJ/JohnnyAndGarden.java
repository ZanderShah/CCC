package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class JohnnyAndGarden
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String f = br.readLine();
		String name = f;
		String ext = "";
		
		boolean has = false;
		
		for (int i = 0; i < f.length(); i++)
		{
			if (f.charAt(i) == '.')
			{
				name = f.substring(0, i);
				ext = f.substring(i + 1);
				has = true;
				break;
			}
		}
		
		if (!has)
			ext = br.readLine();
		
		System.out.println("\"" + name + "\" - " + ext.toLowerCase());

	}

}
