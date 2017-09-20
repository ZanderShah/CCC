package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class BlackAndWhite
{

	public static void main(String[] args) throws Exception
	{
		final Comparator<Integer[]> inc = new Comparator<Integer[]>() {
			public int compare(Integer[] a, Integer[] b)
			{
				return a[0] - b[0];
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int t = Integer.parseInt(st.nextToken());

		ArrayList<Integer[]> line = new ArrayList<Integer[]>();
		TreeSet<Integer> p = new TreeSet<Integer>();

		for (int i = 0; i < t; i++)
		{
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = x1 + Integer.parseInt(st.nextToken());
			int y2 = y1 + Integer.parseInt(st.nextToken());

			line.add(new Integer[] { x1, y1, y2});
			line.add(new Integer[] { x2, y1, y2});
			p.add(y1);
			p.add(y2);
		}

		Collections.sort(line, inc);
		ArrayList<Integer> y = new ArrayList<Integer>(p);

		int area = 0;
		boolean[] cur = new boolean[y.size() + 1];

		for (int i = 0; i < line.size(); i++)
		{
			Integer[] c = line.get(i);

			if (i != 0)
			{
				Integer[] b = line.get(i - 1);
				for (int j = 1; j < y.size(); j++)
					if (cur[j])
						area += (y.get(j) - y.get(j - 1)) * (c[0] - b[0]);
			}

			int s = Math.abs(Collections.binarySearch(y, c[1]) + 1);
			int e = Math.abs(Collections.binarySearch(y, c[2]) + 1);

			for (int j = s; j < e; j++)
				if (cur[j])
					cur[j] = false;
				else
					cur[j] = true;
		}

		System.out.println(area);
	}

}
