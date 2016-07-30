package coci;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

// This question hurts me 

public class Niko
{
	public static void main(String[] args) throws Exception
	{
		int N = readInt();
		int[][] F = new int[N][3];

		for (int i = 0; i < N; i++)
		{
			String[] s = readLine().split("-");
			F[i][0] = Integer.parseInt(s[0]);
			F[i][1] = Integer.parseInt(s[1]);
			F[i][2] = Integer.parseInt(s[2]);
		}

		int M = readInt(), A = 0, B = 0, C = 0, A2B = 0, A2C = 0, B2C = 0, A2BC = 0;
		for (int i = 0; i < M; i++)
		{
			String s = readLine();
			if (s.length() == 3)
				A2BC++;
			else if (s.length() == 2)
			{
				if (s.equals("OV") || s.equals("VO"))
					A2B++;
				else if (s.equals("VN") || s.equals("NV"))
					B2C++;
				else
					A2C++;
			}
			else
			{
				if (s.equals("O"))
					A++;
				else if (s.equals("V"))
					B++;
				else
					C++;
			}
		}

		for (int i = 0, x, y, z, ab, ac, bc, abc; i < N; i++)
		{
			x = A + A2B + A2C + A2BC;
			y = B + B2C;
			z = C;
			ab = A2B;
			ac = A2C;
			bc = B2C;
			abc = A2BC;
			
			while (y - F[i][1] < 0)
			{
				if (x - F[i][0] > 0 && (ab > 0 || abc > 0))
				{
					y++;
					x--;
					if (ab > 0)
						ab--;
					else
						abc--;
				}
				else
					break;
			}
			
			while (z - F[i][2] < 0)
			{
				if (x - F[i][0] > 0 && (ac > 0 || abc > 0))
				{
					z++;
					x--;
					if (ac > 0)
						ac--;
					else
						abc--;
				}
				else if (y - F[i][1] > 0 && bc > 0)
				{
					z++;
					y--;
					bc--;
				}
				else if (x - F[i][0] > 0 && ab > 0 && bc > 0)
				{
					ab--;
					x--;
					y++;
				}
				else
					break;
			}
			
			if (x >= F[i][0] && y >= F[i][1] && z >= F[i][2])
				System.out.println("DA");
			else
				System.out.println("NE");
		}
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

	static long readLong() throws IOException
	{
		return Long.parseLong(next());
	}

	static int readInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException
	{
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException
	{
		return next().charAt(0);
	}

	static String readLine() throws IOException
	{
		return br.readLine().trim();
	}
}
