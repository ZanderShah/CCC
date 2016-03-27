package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class ShahirInABox
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int x1 = 1000;
		int x2 = 0;
		int y1 = 1000;
		int y2 = 0;
		
		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			if (x >= x2)
				x2 = x;
			if (x <= x1)
				x1 = x;
			
			if (y >= y2)
				y2 = y;
			if (y <= y1)
				y1 = y;
		}

		System.out.println((x2 - x1) * (y2 - y1));
	}

}
