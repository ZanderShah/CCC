package DMOJ;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Sysadmin
{
	public static void main(String[] args) throws Exception
	{
		final Comparator<Integer[]> slope = new Comparator<Integer[]>() {
			public int compare(Integer[] o1, Integer[] o2)
			{
				return o1[1] - o2[1];
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int n = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());

		ArrayList<Integer> b = new ArrayList<Integer>();
		ArrayList<Integer> m = new ArrayList<Integer>();
		Integer[][] d = new Integer[n][2];

		int max = 0;

		for (int i = 0; i < n; i++)
		{
			st = new StringTokenizer(br.readLine());
			b.add(Integer.parseInt(st.nextToken()));
			m.add(Integer.parseInt(st.nextToken()));
			d[i][0] = b.get(i);
			d[i][1] = m.get(i);

			if (b.get(i) > b.get(max) && m.get(i) >= m.get(max))
				max = i;
		}

		ArrayList<Integer[]> keep = new ArrayList<Integer[]>();
		for (int i = 0; i < n; i++)
			if (d[i][0] > d[max][0] || d[i][1] >= d[max][1])
				keep.add(new Integer[] { d[i][0], d[i][1] });

		int pos = 1;

		Collections.sort(keep, slope);

		while (pos < keep.size())
		{
			Integer[] now = keep.get(pos);
			Integer[] back = keep.get(pos - 1);

			if (now[1].equals(back[1]))
			{
				if (now[0].compareTo(back[0]) <= 0)
					keep.remove(pos);
				else
					keep.remove(pos - 1);
			}
			else
				pos++;
		}

		Stack<Integer[]> stack = new Stack<Integer[]>();
		stack.push(keep.get(0));

		if (keep.size() > 1)
			stack.push(keep.get(1));

		for (int i = 2; i < keep.size(); i++)
		{
			Integer[] l = keep.get(i);
			Integer[] a = stack.get(stack.size() - 1);
			Integer[] c = stack.get(stack.size() - 2);

			while ((c[0] - l[0]) * 1.0 / (l[1] - c[1]) < (c[0] - a[0])
					* 1.0
					/ (a[1] - c[1]) && stack.size() > 1)
			{
				stack.pop();

				a = stack.get(stack.size() - 1);

				if (stack.size() > 1)
					c = stack.get(stack.size() - 2);
			}

			stack.push(l);
		}
		
		Integer[][] ans1 = new Integer[stack.size()][2];
		
		for (int i = 0; i < ans1.length; i++)
			ans1[i] = stack.get(i);
		
		double[] ans = new double[stack.size() - 1];
		
		for (int i = 1; i < ans.length; i++)
		{
			Integer[] a = stack.get(i);
			Integer[] c = stack.get(i - 1);
			
			ans[i] = (c[0] - a[0]) * 1.0 / (a[1] - c[1]);
		}

		for (int i = 0; i < q; i++)
		{
			int qu = Integer.parseInt(br.readLine());
			int x = Arrays.binarySearch(ans, qu);

			if (x < 0)
				x = -x - 1;

			Integer[] answer = stack.get(x);

			for (int j = 0; j < d.length; j++)
				if (answer[0] + answer[1] * qu == d[j][0] + d[j][1] * qu)
				{
					System.out.println(j);
					break;
				}
			max = 0;
			
			for (int j = 1; j < ans1.length; j++)
				if (ans1[j][0] + ans1[j][1] * qu > ans1[max][0] + ans1[max][1] * qu)
					max = j;
			
			for (int j = 0; j < d.length; j++)
				if (ans1[max][0] + ans1[max][1] * qu == d[j][0] + d[j][1] * qu)
				{
					System.out.println(j);
					break;
				}
			
			System.out.println();
		}
	}
}
