package cco;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Cows {

	static class Point implements Comparable<Point> {
		double x, y;

		Point(double xx, double yy) {
			x = xx;
			y = yy;
		}

		public int compareTo(Point p) {
			if (x == p.x)
				return ((Double) y).compareTo(p.y);
			return ((Double) x).compareTo(p.x);
		}

		public String toString() {
			return x + " " + y;
		}

		public Point subtract(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		public Point divide(Double scalar) {
			return new Point(x / scalar, y / scalar);
		}
	}

	static double cross(Point a, Point b, Point c) {
		return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	}

	static double cross2(Point a, Point b) {
		return a.x * b.y - a.y * b.x;
	}

	static double dot(Point a, Point b) {
		return a.x * b.x + a.y * b.y;
	}

	static double dist(Point a, Point b) {
		return Math.sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}

	public static void main(String[] args) throws IOException {
		int n = readInt();

		Point[] p = new Point[n];
		for (int i = 0; i < n; i++)
			p[i] = new Point(readInt(), readInt());
		Arrays.sort(p);

		ArrayList<Point> c = new ArrayList<Point>();

		// Monotone chain
		for (int i = 0; i < n; i++) {
			while (c.size() >= 2 && cross(c.get(c.size() - 2), c.get(c.size() - 1), p[i]) <= 0)
				c.remove(c.size() - 1);
			c.add(p[i]);
		}

		for (int i = n - 1, t = c.size() + 1; i >= 0; i--) {
			while (c.size() >= t && cross(c.get(c.size() - 2), c.get(c.size() - 1), p[i]) <= 0)
				c.remove(c.size() - 1);
			c.add(p[i]);
		}

		double ans = 0;
		for (int i = 1; i < c.size(); i++)
			ans += c.get(i - 1).x * c.get(i).y - c.get(i - 1).y * c.get(i).x;
		System.out.printf("%d\n", (int) (ans / 100));
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