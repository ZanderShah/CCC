package ecoo;
import java.io.BufferedReader;
import java.io.InputStreamReader;


public class NeanderthalNumbers
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int c = 0; c < 10; c++)
		{
			String n = br.readLine();
			int[] dp = new int[n.length() + 1];
			for (int i = 0; i < n.length(); i++)
			{
				if (i + 1 < n.length())
				{
					String s = n.substring(i, i + 2);
					if (s.equals("ug"))
						if (i == 0)
							dp[i + 2]++;
						else
							dp[i + 2] += dp[i];
				}
				if (i + 2 < n.length())
				{
					String s = n.substring(i, i + 3);
					if (s.equals("ook") || s.equals("oog"))
						if (i == 0)
							dp[i + 3]++;
						else
							dp[i + 3] += dp[i];
				}
				if (i + 3 < n.length())
				{
					String s = n.substring(i, i + 4);
					if (s.equals("ooga") || s.equals("mook") || s.equals("ugug"))
						if (i == 0)
							dp[i + 4]++;
						else
							dp[i + 4] += dp[i];
				}
				if (i + 4 < n.length())
				{
					String s = n.substring(i, i + 5);
					if (s.equals("oogam") || s.equals("oogum"))
						if (i == 0)
							dp[i + 5]++;
						else
							dp[i + 5] += dp[i];
				}
				if (i + 5 < n.length())
				{
					String s = n.substring(i, i + 6);
					if (s.equals("ookook"))
						if (i == 0)
							dp[i + 6]++;
						else
							dp[i + 6] += dp[i];
				}
				if (i + 7 < n.length())
				{
					String s = n.substring(i, i + 8);
					if (s.equals("mookmook"))
						if (i == 0)
							dp[i + 8]++;
						else
							dp[i + 8] += dp[i];
				}
			}
			
			System.out.println(dp[n.length()]);
		}
	}

}
