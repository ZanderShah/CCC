package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

// Super sketchy solution but works
// The intended solution is bitmask dp but when I wrote this contest I didn't know that
public class CakeBalancing
{
	public static int min, weight;

	public static void solve2(ArrayList<Integer> l, ArrayList<Integer> r,
			int wL, int wR, int s)
	{
		if (s < min)
		{
			if (l.size() == 0 && r.size() == 0)
				min = s;
			else
			{
				int q = 0;

				for (int i = r.size() - 1; i >= 0; i--)
				{
					q += r.get(i);
					wR -= r.get(i);
					if (Math.abs(wR - wL) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j = 0; j < i; j++)
							c.add(r.get(j));

						solve2(l, c, wL, wR, s + 1);
					}
					else
					{
						wR += q;
						break;
					}
				}

				q = 0;

				for (int i = l.size() - 1; i >= 0; i--)
				{
					q += l.get(i);
					wL -= l.get(i);
					if (Math.abs(wR - wL) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j = 0; j < i; j++)
							c.add(l.get(j));

						solve2(c, r, wL, wR, s + 1);
					}
					else
					{
						wL += q;
						break;
					}
				}

				q = 0;

				for (int i = 0; i < l.size(); i++)
				{
					wL -= l.get(i);
					q +=
							l.get(i);
					if (Math.abs(wL - wR) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j =
								i + 1; j < l.size(); j++)
							c.add(l.get(j));

						solve2(c, r, wL, wR, s + 1);
					}
					else
					{
						wL += q;
						break;
					}
				}

				q = 0;

				for (int i = 0; i < r.size(); i++)
				{
					wR -= r.get(i);
					q +=
							r.get(i);
					if (Math.abs(wL - wR) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j =
								i + 1; j < r.size(); j++)
							c.add(r.get(j));

						solve2(l, c, wL, wR, s + 1);
					}
					else
					{
						wR += q;
						break;
					}
				}
				
				if (r.size() > 2
						&& Math.abs(wR - (wL - r.get(r.size() - 1) - r.get(0))) <= weight)
				{
					ArrayList<Integer> c = new ArrayList<Integer>();
					for (int j = 1; j < r.size() - 1; j++)
						c.add(r.get(j));

					solve2(l, c, wL, wR - r.get(r.size() - 1) - r.get(0), s + 1);
				}

				if (l.size() > 2
						&& Math.abs(wR - (wL - l.get(l.size() - 1) - l.get(0))) <= weight)
				{
					ArrayList<Integer> c = new ArrayList<Integer>();
					for (int j = 1; j < l.size() - 1; j++)
						c.add(l.get(j));

					solve2(c, r, wL - l.get(l.size() - 1) - l.get(0), wR, s + 1);

				}
			}
		}
	}

	public static void solve(ArrayList<Integer> l, ArrayList<Integer> r,
			int wL, int wR, int s)
	{
		if (s < min)
		{
			if (l.size() == 0 && r.size() == 0)
				min = s;
			else
			{
				int q = 0;

				for (int i = r.size() - 1; i >= 0; i--)
				{
					q += r.get(i);
					wR -= r.get(i);
					if (Math.abs(wR - wL) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j = 0; j < i; j++)
							c.add(r.get(j));

						solve(l, c, wL, wR, s + 1);
					}
					else
					{
						wR += q;
						break;
					}
				}

				q = 0;

				for (int i = l.size() - 1; i >= 0; i--)
				{
					q += l.get(i);
					wL -= l.get(i);
					if (Math.abs(wR - wL) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j = 0; j < i; j++)
							c.add(l.get(j));

						solve(c, r, wL, wR, s + 1);
					}
					else
					{
						wL += q;
						break;
					}
				}

				q = 0;

				for (int i = 0; i < l.size(); i++)
				{
					wL -= l.get(i);
					q +=
							l.get(i);
					if (Math.abs(wL - wR) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j =
								i + 1; j < l.size(); j++)
							c.add(l.get(j));

						solve(c, r, wL, wR, s + 1);
					}
					else
					{
						wL += q;
						break;
					}
				}

				q = 0;

				for (int i = 0; i < r.size(); i++)
				{
					wR -= r.get(i);
					q +=
							r.get(i);
					if (Math.abs(wL - wR) <= weight)
					{
						ArrayList<Integer> c = new ArrayList<Integer>();
						for (int j =
								i + 1; j < r.size(); j++)
							c.add(r.get(j));

						solve(l, c, wL, wR, s + 1);
					}
					else
					{
						wR += q;
						break;
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int left = Integer.parseInt(st.nextToken());
		int right = Integer.parseInt(st.nextToken());

		weight = Integer.parseInt(st.nextToken());
		min = Integer.MAX_VALUE;

		ArrayList<Integer> l = new ArrayList<Integer>();
		ArrayList<Integer> r = new ArrayList<Integer>();

		int wL = 0;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < left; i++)
		{
			int w = Integer.parseInt(st.nextToken());
			wL += w;
			l.add(w);
		}
		int wR = wL;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < right; i++)
			r.add(Integer.parseInt(st.nextToken()));

		Collections.sort(l);
		Collections.sort(r);

		solve(l, r, wL, wR, 0);
		solve2(l, r, wL, wR, 0);

		System.out.println(min);
	}

}
