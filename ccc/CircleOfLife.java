package ccc;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CircleOfLife
{
	static int[] move(int i, int[] old)
	{
		int[] newState = new int[n];
		int a = (int) ((1l << i) % n);
		int b = (int) ((2 * n - a) % n);
		for (int j = 0; j < n; j++)
			newState[j] = old[(j + a) % n] ^ old[(j + b) % n];
		return newState;
	}
	
	static int n;

	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(
				new OutputStreamWriter(System.out)));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		long t = Long.parseLong(st.nextToken());
		
		String state = br.readLine();
		int[] start = new int[n];
		for (int i = 0; i < n; i++)
			start[i] = state.charAt(i) - '0';

		for (int i = 0; i < 50; i++)
			if ((t >> i & 1) != 0)
				start = move(i, start);

		for (int i = 0; i < n; i++)
			out.print(start[i]);
		out.close();
	}
}