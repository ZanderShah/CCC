package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class LightsGoingOnOff
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int r = Integer.parseInt(br.readLine());
		int l = Integer.parseInt(br.readLine());
		
		int[] initial = new int[r];
		for (int i = 0; i < r; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int multi = 1;
			for (int j = 0; j < l; j++)
			{
				if (st.nextToken().charAt(0) == '1')
					initial[i] += multi;
				multi *= 2;
			}
		}
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(initial[0]);
		
		for (int i = 1; i < r; i++)
		{
			int row = q.size();
			for (int j = 0; j < row; j++)
				q.add(q.poll() ^ initial[i]);
			q.add(initial[i]);
		}
		
		boolean[] repeat = new boolean[1 << 8];
		int total = 0;
		while (!q.isEmpty())
		{
			int x = q.poll();
			if (!repeat[x])
			{
				total++;
				repeat[x] = true;
			}
		}
		
		System.out.println(total);
	}

}
