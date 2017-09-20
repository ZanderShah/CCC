package dmoj;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Rocks
{
	public static int size;

	public static int mass(String s)
	{
		int m = 0;

		for (int i = 0; i < s.length(); i++)
		{
			m += s.charAt(i) - 'a' + 1;
		}

		return m;
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int c = Integer.parseInt(br.readLine());

		String[] names = new String[1000000];
		Arrays.fill(names, "");
		int[] mass = new int[1000000];
		int[] sum = new int[1000000];
		size = 0;
		HashMap<String, Integer> map = new HashMap<String, Integer>();

		for (int j = 0; j < c; j++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine());

			char t = st.nextToken().charAt(0);

			if (t == 'N')
				System.out.println(size);
			else if (t == 'A')
			{
				String s = st.nextToken();
				if (map.containsKey(s))
					System.out.println("Can't add " + s);
				else
				{
					names[size + 1] = s;
					mass[size + 1] = mass(s);
					map.put(s, size + 1);
					sum[size + 1] = mass[size + 1] + sum[size];
					size++;
				}
			}
			else
			{
				String x = st.nextToken();
				String y = st.nextToken();
				int a = map.get(x);
				int b, edit;

				if (t == 'S')
				{
					b = map.get(y);
					names[a] = y;
					names[b] = x;
					int temp = mass[b];
					mass[b] = mass[a];
					mass[a] = temp;
					map.remove(x);
					map.remove(y);
					map.put(x, b);
					map.put(y, a);
					
					edit = mass[Math.max(a, b)] - mass[Math.min(a, b)];

					for (int i = Math.min(a, b); i < Math.max(a, b); i++)
						sum[i] -= edit;
				}
				else if (t == 'R')
				{
					names[a] = y;
					map.remove(x);
					map.put(y, a);
					
					int temp = mass[a];
					mass[a] = mass(y);
					edit = temp - mass[a];

					for (int i = a; i < 1000000; i++)
					{
						if (mass[i] == 0)
							break;
						sum[i] -= edit;
					}
				}
				else if (t == 'M')
				{
					b = map.get(y);
					
					if (Math.min(a, b) - 1 >= 0)
						System.out.println(sum[Math.max(a, b)]
								- sum[Math.min(a, b) - 1]);
					else
						System.out.println(sum[Math.max(a, b)]);
				}
			}
		}

	}

}
