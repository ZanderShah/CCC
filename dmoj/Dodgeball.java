package dmoj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Dodgeball {

	public static void main(String[] args) throws Exception {
		int n = readInt();
		int[] dp = new int[n + 1];
		String[] s = new String[n + 1];
		s[0] = "$";
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			s[i] = next().toLowerCase();
			if (s[i].charAt(0) == s[i - 1].charAt(0))
				dp[i] += dp[i - 1];
			dp[0] += dp[i];
		}
		System.out.println(dp[0]);
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
