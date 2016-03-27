package TLE;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Poetry
{
	static class Word 
	{
		int l, r;
		String w;
		Word(String ww)
		{
			w = ww;
			l = 0;
			r = w.length();
		}
		
		void print()
		{
			for (int i = l; i < r; i++)
				out.print(w.charAt(i));
		}

		int length()
		{
			return r - l;
		}
	}
	
	static PrintWriter out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(System.out)));
	
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(
				System.in));		

		int n = Integer.parseInt(br.readLine());
		int[] c = new int[n];
		for (int i = 0; i < n; i++)
			c[i] = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		Word[] words = new Word[st.countTokens()];
		for (int i = 0; i < words.length; i++)
			words[i] = new Word(st.nextToken());

		int x = 0;
		int l = 0;

		for (int i = 0; i < words.length; i++)
		{
			if (x == 0)
				if (words[i].length() <= c[l])
				{
					words[i].print();
					x += words[i].length();
				}
				else
				{
					words[i].r = words[i].l + c[l];
					words[i].print();
					out.println();
					words[i].l += c[l];
					words[i].r = words[i].w.length();
					l = (l + 1) % n;
					i--;
				}
			else
				if (x + words[i].length() <= c[l])
				{
					words[i].print();
					x += words[i].length();
				}
				else
				{
					out.println();
					x = 0;
					l = (l + 1) % n;
					i--;
				}

			if (x >= c[l])
			{
				out.println();
				x = 0;
				l = (l + 1) % n;
			}

			if (x != 0)
			{
				out.print(" ");
				x++;

				if (x >= c[l])
				{
					out.println();
					x = 0;
					l = (l + 1) % n;
				}
			}
		}
		
		out.close();
	}
}