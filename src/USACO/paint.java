package USACO;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class paint
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("paint.in"));
		PrintWriter out = new PrintWriter(new FileWriter("paint.out"));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		if (a > c && a > d || b < c && b < d)
			out.println(b - a + d - c);
		else if (c > a && b > d)
			out.println(b - a);
		else if (a > c && d > b)
			out.println(d - c);
		else if (c > a)
			out.println(d - a);
		else if (b > d)
			out.println(b - c);
		else if (a == c && b == d)
			out.println(b - a);
		
		out.close();

	}

}
