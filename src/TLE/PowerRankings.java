package TLE;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class PowerRankings
{
	static class Student implements Comparable<Student>
	{
		String name;
		int time;
		public Student(String n)
		{
			name = n;
			time = 0;
		}
		
		public int compareTo(Student s)
		{
			return s.time - time;
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		int n = readInt();
		int p = readInt();
		
		Student[] students = new Student[n];
		for (int i = 0; i < n; i++)
			students[i] = new Student(readLine());
		
		for (int i = 0; i < p; i++)
			for (int j = 0; j < n; j++)
				students[j].time += readInt();
		
		Arrays.sort(students);
		
		for (int i = 3; i < n + 3; i++)
			System.out.printf("%d. %s\n", i, students[i - 3].name);
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
