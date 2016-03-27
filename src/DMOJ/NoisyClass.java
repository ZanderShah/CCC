package DMOJ;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class NoisyClass
{
	public static boolean[] checked;
	public static boolean loop;
	public static Students[] noisy;

	public static class Students
	{
		ArrayList<Integer> kid = new ArrayList<Integer>();
	}

	public static void solve(int m, boolean[][] v)
	{
		checked[m] = true;

		for (Integer i : noisy[m].kid)
		{
			if (v[m][i])
			{
				loop = true;
				return;
			}

			v[m][i] = true;

			solve(i, v);
		}
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());

		noisy = new Students[n];
		for (int i = 0; i < n; i++)
			noisy[i] = new Students();

		for (int i = 0; i < m; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			Integer a = Integer.parseInt(st.nextToken()) - 1;
			Integer b = Integer.parseInt(st.nextToken()) - 1;
			if (!noisy[a].kid.contains(b))
				noisy[a].kid.add(b);
		}

		boolean b = true;
		checked = new boolean[n];
		loop = false;
		boolean[][] v = new boolean[n][n];

		for (int i = 0; i < n && !loop; i++)
			if (!checked[i] && noisy[i].kid.size() != 0)
				solve(i, v);

		if (loop)
			System.out.println("N");
		else
			System.out.println("Y");
	}

}
