package CCC;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

/*
 * Java implementation of solution from mmhs.ca
 * The general idea is that it does a sweeping line over the x-axis by adding
 * tint where the pane starts and removing tint right after the pane ends
 */
public class TintedGlassWindow
{

	public static void main(String[] args) throws Exception
	{
		final Comparator<Long[]> inc = new Comparator<Long[]>() {
			public int compare(Long[] a, Long[] b)
			{
				return (int) (a[0] - b[0]);
			}
		};

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int t = Integer.parseInt(br.readLine());

		ArrayList<Long[]> line = new ArrayList<Long[]>();
		TreeSet<Long> p = new TreeSet<Long>();

		for (int i = 0; i < n; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			long x1 = Integer.parseInt(st.nextToken());
			long y1 = Integer.parseInt(st.nextToken());
			long x2 = Integer.parseInt(st.nextToken());
			long y2 = Integer.parseInt(st.nextToken());
			long ti = Integer.parseInt(st.nextToken());

			line.add(new Long[] { x1, y1, y2, ti });
			line.add(new Long[] { x2, y1, y2, -ti });
			p.add(y1);
			p.add(y2);
		}

		Collections.sort(line, inc);
		ArrayList<Long> y = new ArrayList<Long>(p);

		long area = 0;
		long[] cur = new long[y.size() + 1];

		for (int i = 0; i < line.size(); i++)
		{
			Long[] c = line.get(i);

			if (i > 0)
			{
				Long[] b = line.get(i - 1);
				for (int j = 1; j < y.size(); j++)
					if (cur[j] >= t)
						area += (y.get(j) - y.get(j - 1)) * (c[0] - b[0]);
			}

			int s = Math.abs(Collections.binarySearch(y, c[1]) + 1);
			int e = Math.abs(Collections.binarySearch(y, c[2]) + 1);

			for (int j = s; j < e; j++)
				cur[j] += c[3];
		}

		System.out.println(area);
	}
}
