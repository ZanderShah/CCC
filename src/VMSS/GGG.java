package VMSS;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class GGG
{
	static int CeilIndex(int A[], int l, int r, int key)
	{
		while (r - l > 1)
		{
			int m = l + (r - l) / 2;
			if (A[m] >= key)
				r = m;
			else
				l = m;
		}

		return r;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());
		TreeMap<Integer, Integer> j = new TreeMap<Integer, Integer>();

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++)
			j.put(Integer.parseInt(st.nextToken()), i);

		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		ArrayList<Integer> c = new ArrayList<Integer>();

		for (int i = 0; i < m; i++)
		{
			Integer a = j.get(Integer.parseInt(st.nextToken()));
			if (a != null)
				c.add(a);
		}
		
		if (c.size() > 0)
		{
			int answer = 1;
			int[] ans = new int[c.size()];

			ans[0] = c.get(0);

			for (int i = 1; i < c.size(); i++)
			{
				if (c.get(i) < ans[0])
					ans[0] = c.get(i);
				else if (c.get(i) > ans[answer - 1])
				{
					ans[answer] = c.get(i);
					answer++;
				}
				else
					ans[CeilIndex(ans, -1, answer - 1, c.get(i))] = c.get(i);
			}

			System.out.println(answer);
		}
		else
			System.out.println(0);
	}
}