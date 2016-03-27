package CCC;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class TruckingTroubles
{
	static class City
	{
		ArrayList<Road> roads = new ArrayList<Road>();

		City()
		{

		}
	}

	static class Road
	{
		int d;
		int w;

		Road(int d, int w)
		{
			this.d = d;
			this.w = w;
		}
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int c = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());

		City[] cities = new City[c];
		for (int i = 0; i < c; i++)
			cities[i] = new City();

		for (int i = 0; i < r; i++)
		{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int weight = Integer.parseInt(st.nextToken());

			cities[a].roads.add(new Road(b, weight));
			cities[b].roads.add(new Road(a, weight));
		}

		int[] de = new int[d];
		for (int i = 0; i < d; i++)
			de[i] = Integer.parseInt(br.readLine()) - 1;

		int[] mst = new int[c];

		// Greedily determine the route to take by always choosing
		// the road with the maximum weight capacity
		for (int i = 0; i < c; i++)
			for (Road j : cities[i].roads)
				mst[j.d] = Math.max(mst[j.d], j.w);

		// The maximum possible weight carries is the minimum accross all
		// the used edges
		int min = Integer.MAX_VALUE;
		for (int i : de)
			if (mst[i] < min)
				min = mst[i];

		System.out.println(min);
	}

}
