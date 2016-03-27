package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class AllOutWar
{
	static int[] seg;
	static int mint = 1 << 30, minv;

	static void update(int l, int r, int c)
	{
		minv = 1 << 30;
		for (int i = l; i < r; i++)
		{
			seg[i] = Math.max(0, seg[i] - c);
			minv = Math.min(minv, seg[i]);
		}
		
		mint = Math.min(minv, mint);
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = readInt();
		int q = readInt();
		seg = new int[n];

		for (int i = 0; i < n; i++)
		{
			seg[i] = readInt();
			mint = Math.min(mint, seg[i]);
		}
		
		for (int i = 0, a, b, c; i < q; i++)
		{
			a = readInt();
			b = readInt();
			c = readInt();
			
			update(a - 1, b, c);
			out.println(minv + " " + mint);
		}
		out.close();
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(
			System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException
	{
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

}