import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * Annoying geometry problem
 * Goes through every line in every object and checks where the 
 * intersection points are if any
 */
public class TinCanTelephone
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int xR = Integer.parseInt(st.nextToken());
		int yR = Integer.parseInt(st.nextToken());
		int xJ = Integer.parseInt(st.nextToken());
		int yJ = Integer.parseInt(st.nextToken());

		double m = Integer.MAX_VALUE;
		if (xR - xJ != 0)
			m = (yR - yJ) * 1.0 / (xR - xJ);

		double b = yR - m * xR;

		st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = 0;

		for (int i = 0; i < r; i++)
		{
			st = new StringTokenizer(br.readLine());
			int ver = Integer.parseInt(st.nextToken());

			int[][] v = new int[ver][2];

			for (int j = 0; j < ver; j++)
			{
				v[j][0] = Integer.parseInt(st.nextToken());
				v[j][1] = Integer.parseInt(st.nextToken());
				
				if (j != 0)
				{
					if (m * v[j][0] + b == v[j][1]
							&& (Math.min(v[j][0], v[j - 1][0]) <= Math.max(xJ, xR) || 
							Math.max(v[j][0], v[j - 1][0]) <= Math.min(xJ, xR)))
					{
						c++;
						break;
					}
					
					double p = Integer.MAX_VALUE;
					if (v[j][0] - v[j - 1][0] != 0)
						p = (v[j][1] - v[j - 1][1]) * 1.0
								/ (v[j][0] - v[j - 1][0]);

					double q = v[j][1] - p * v[j][0];

					if (m == Integer.MAX_VALUE
							&& Math.min(v[j][0], v[j - 1][0]) <= xJ
							&& Math.max(v[j][0], v[j - 1][0]) >= xJ
							&& Math.min(yJ, yR) <= p * xJ + q
							&& Math.max(yJ, yR) >= p * xJ + q)
					{
						c++;
						break;
					}
					else if (p == Integer.MAX_VALUE
							&& Math.min(xJ, xR) <= v[j][0]
							&& Math.max(xJ, xR) >= v[j][0]
							&& Math.min(v[j][1], v[j - 1][1]) <= m * v[j][0]
									+ b
							&& Math.max(v[j][1], v[j - 1][1]) >= m * v[j][0]
									+ b)
					{
						c++;
						break;
					}
					else
					{
						double poi = (q - b) / (m - p);

						if (poi >= Math.min(xJ, xR) && poi <= Math.max(xJ, xR)
								&& poi <= Math.max(v[j][0], v[j - 1][0])
								&& poi >= Math.min(v[j][0], v[j - 1][0]))
						{
							c++;
							break;
						}
					}
				}
			}
		}

		System.out.println(c);
	}
}
