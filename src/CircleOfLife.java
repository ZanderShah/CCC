import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.StringTokenizer;

/**
 * Alexander Shah
 * Richmond Hill High School
 * 073832644
 * Senior
 * S5
 */
public class CircleOfLife
{
	static void generateStates(ArrayList<String> state)
	{
		while (true)
		{
			String next = nextState(state.get(state.size() - 1));

			if (map.containsKey(next))
				u = map.get(next);
			
			if (u != -1 || state.size() > t)
			{
				return;
			}

			state.add(next);
			map.put(next, state.size() - 1);
		}
	}

	static String nextState(String state)
	{
		String next = "";
		for (int i = 0; i < n; i++)
			if (state.charAt((i + 1) % n) != state.charAt((i - 1 + n) % n))
				next += "1";
			else
				next += "0";
		return next;
	}

	static long t;
	static int n;
	static int u = -1;
	static HashMap<String, Integer> map;

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		map = new HashMap<String, Integer>();
		
		n = Integer.parseInt(st.nextToken());
		t = Long.parseLong(st.nextToken());

		ArrayList<String> state = new ArrayList<String>();
		state.add(br.readLine());

		generateStates(state);

		if (u != -1 && t >= u)
		{
			t -= u;
			out.println(state.get((int) (t % (state.size() - u) + u)));
		}
		else
			out.println(state.get((int) t));

		out.close();
	}
}