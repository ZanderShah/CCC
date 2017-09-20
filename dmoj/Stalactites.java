package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Stalactites
{
	static int n;
	static long[][][] bit;
	static int[][][] val;

	static void update(int x, int y, int z, int v)
	{
		for (; x <= n; x += (x & (-x)))
		{
			int yo = y;
			for (; yo <= n; yo += (yo & (-yo)))
			{
				int zo = z;
				for (; zo <= n; zo += (zo & (-zo)))
					bit[x][yo][zo] += v;
			}
		}
	}

	static long sum(int x1, int y1, int z1, int x2, int y2, int z2)
	{
		long ans = 0;
		while (x1 > 0 || x2 > 0)
		{
			if (x1 > 0)
			{
				int ya = y1;
				int yb = y2;

				while (ya > 0 || yb > 0)
				{
					if (ya > 0)
					{
						int za = z1;
						int zb = z2;

						while (za > 0 || zb > 0)
						{
							if (za > 0)
							{
								ans -= bit[x1][ya][za];
								za -= za & (-za);
							}
							if (zb > 0)
							{
								ans += bit[x1][ya][zb];
								zb -= zb & (-zb);
							}
						}

						ya -= ya & (-ya);
					}
					if (yb > 0)
					{
						int za = z1;
						int zb = z2;

						while (za > 0 || zb > 0)
						{
							if (za > 0)
							{
								ans += bit[x1][yb][za];
								za -= za & (-za);
							}
							if (zb > 0)
							{
								ans -= bit[x1][yb][zb];
								zb -= zb & (-zb);
							}
						}

						yb -= yb & (-yb);
					}
				}

				x1 -= x1 & (-x1);
			}
			if (x2 > 0)
			{
				int ya = y1;
				int yb = y2;
				
				while (ya > 0 || yb > 0)
				{
					if (ya > 0)
					{
						int za = z1;
						int zb = z2;

						while (za > 0 || zb > 0)
						{
							if (za > 0)
							{
								ans += bit[x2][ya][za];
								za -= za & (-za);
							}
							if (zb > 0)
							{
								ans -= bit[x2][ya][zb];
								zb -= zb & (-zb);
							}
						}

						ya -= ya & (-ya);
					}
					if (yb > 0)
					{
						int za = z1;
						int zb = z2;

						while (za > 0 || zb > 0)
						{
							if (za > 0)
							{
								ans -= bit[x2][yb][za];
								za -= za & (-za);
							}
							if (zb > 0)
							{
								ans += bit[x2][yb][zb];
								zb -= zb & (-zb);
							}
						}

						yb -= yb & (-yb);
					}
				}
				
				x2 -= x2 & (-x2);
			}
		}
		
		return ans;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		bit = new long[n + 1][n + 1][n + 1];
		val = new int[n + 1][n + 1][n + 1];

		int m = Integer.parseInt(br.readLine());
		long total = 0;
		for (int i = 0; i < m; i++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());
			char c = st.nextToken().charAt(0);
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int z1 = Integer.parseInt(st.nextToken());

			if (c == 'C')
			{
				int v = Integer.parseInt(st.nextToken());
				update(x1, y1, z1, v - val[x1][y1][z1]);
				val[x1][y1][z1] = v;
			}
			else
			{
				int x2 = Integer.parseInt(st.nextToken());
				int y2 = Integer.parseInt(st.nextToken());
				int z2 = Integer.parseInt(st.nextToken());
				x1--;
				y1--;
				z1--;
				total += sum(x1, y1, z1, x2, y2, z2);
			}
		}
		System.out.println(total);
	}

}
