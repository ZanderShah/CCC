package DMOJ;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FiannaRayOrdesia
{
	static double x1, y1, x2, y2, d, M, A, B, B2, C, xx1, yy1, xx2, yy2;

	public static void main(String[] args) throws Exception
	{
		x1 = readDouble();
		y1 = readDouble();
		x2 = readDouble();
		y2 = readDouble();
		d = readDouble();

		M = - (x2 - x1) / (y2 - y1);
		B2 = (y1 + y2) / 2 - M * (x1 + x2) / 2;

		if (x1 == x2)
		{
			yy1 = yy2 = (y1 + y2) / 2;
			xx1 = x1
					- Math.sqrt(d * d - (yy1 - Math.min(y1, y2))
							* (yy1 - Math.min(y1, y2)));
			xx2 = x1
					+ Math.sqrt(d * d - (yy1 - Math.min(y1, y2))
							* (yy1 - Math.min(y1, y2)));
		}
		else if (y1 == y2)
		{
			xx1 = xx2 = (x1 + x2) / 2;
			yy1 = y1
					- Math.sqrt(d * d - (xx1 - Math.min(x1, x2))
							* (xx1 - Math.min(x1, x2)));
			yy2 = y1
					+ Math.sqrt(d * d - (xx1 - Math.min(x1, x2))
							* (xx1 - Math.min(x1, x2)));
		}
		else
		{
			A = 1 + M * M;
			B = -2 * x1 - 2 * y1 * M + 2 * M * B2;
			C = x1 * x1 + y1 * y1 - 2 * y1 * B2 + B2 * B2 - d * d;
			
			xx1 = (-B + Math.sqrt(B * B - 4 * A * C)) / (2 * A);
			xx2 = (-B - Math.sqrt(B * B - 4 * A * C)) / (2 * A);
			
			yy1 = M * xx1 + B2;
			yy2 = M * xx2 + B2;
		}

		if (xx1 == xx2 && yy1 == yy2)
			System.out.printf("%.6f %.6f\n", xx1, yy1);
		else if (xx1 == xx2)
			if (yy1 < yy2)
				System.out.printf("%.6f %.6f\n%.6f %.6f", xx1, yy1, xx1, yy2);
			else
				System.out.printf("%.6f %.6f\n%.6f %.6f", xx1, yy2, xx1, yy1);
		else if (xx1 < xx2)
			System.out.printf("%.6f %.6f\n%.6f %.6f", xx1, yy1, xx2, yy2);
		else
			System.out.printf("%.6f %.6f\n%.6f %.6f", xx2, yy2, xx1, yy1);
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
