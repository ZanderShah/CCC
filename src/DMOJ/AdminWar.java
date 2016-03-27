package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class AdminWar
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int x = 0;
		int f = 0;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringTokenizer at = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < n; i++)
		{
			int tX = Integer.parseInt(st.nextToken());
			int tF = Integer.parseInt(at.nextToken());
			
			if (tX > tF)
				x++;
			else if (tX < tF)
				f++;
		}
		System.out.println(x + " " + f);
		if (x > f)
			System.out.println("Xyene");
		else if (x < f)
			System.out.println("FatalEagle");
		else
			System.out.println("Tie");
	}

}
