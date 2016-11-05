package codeforces;
//package codeforces;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FoodOnThePlane {

	public static void main(String[] args) throws Exception {
		int w[] = { 4, 5, 6, 3, 2, 1 };
		String s = readLine();
		long n = Long.parseLong(s.substring(0, s.length() - 1));
		n--;
		int a = s.charAt(s.length() - 1) - 'a';

		long t = n / 4 * 16 + w[a];
		n %= 4;
		if (n == 1 || n == 3)
			t += 7;
		System.out.println(t);
	}

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

}
