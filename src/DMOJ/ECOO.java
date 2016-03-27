package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class ECOO
{

	public static void main(String[] args) throws Exception
	{
		final Comparator<String[]> points = new Comparator<String[]>() {
			public int compare(String[] o1, String[] o2)
			{
				return Integer.parseInt(o1[2]) - Integer.parseInt(o2[2]);
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		String[][] team = new String[n][3];

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			team[i][0] = st.nextToken();
			team[i][1] = st.nextToken();
			team[i][2] = st.nextToken();
		}

		Arrays.sort(team, points);

		int gen1 = -1;
		int gen2 = -1;
		int girl = -1;

		for (int i = n - 1; i >= 0; i--)
		{
			if (team[i][1].equals("general"))
			{
				if (gen1 == -1)
					gen1 = i;
				else if (gen2 == -1)
					gen2 = i;
			}
			else
			{
				if (girl == -1)
					girl = i;
				else
				{
					if (gen1 == -1)
					{
						gen1 = girl;
						girl = i;
					}
					else if (gen2 == -1)
					{
						gen2 = girl;
						girl = i;
					}
				}
			}
		}

		if (n == 0)
			System.out.println("No ECOO :(");
		else
		{
			ArrayList<String> ecoo = new ArrayList<String>();
			
			if (gen1 != -1)
				ecoo.add(team[gen1][0]);
			if (gen2 != -1) 
				ecoo.add(team[gen2][0]);
			if (girl != -1)
				ecoo.add(team[girl][0]);
			
			Collections.sort(ecoo);

			for (String i : ecoo)
				System.out.println(i);
		}
	}

}
