package ecoo;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CCPlus
{

	public static void main(String[] args) throws Exception
	{
		for (int r = 0; r < 10; r++)
		{
			int num = readInt() % 26;
			String str = readLine();
			StringTokenizer st = new StringTokenizer(str);

			int len = st.countTokens();

			if (len == 1)
			{
				for (int i = str.length() - 1; i >= 0; i--)
				{
					int total = num;
					for (int j = i + 1; j < str.length(); j++)
					{
						total += (str.charAt(j) - 'a');
					}
					total %= 26;
					char newCh = (char) (str.charAt(i) - total);
					if (newCh < 'a')
					{
						newCh += 26;
					}
					str = str.substring(0, i) + newCh
							+ str.substring(i + 1, str.length());

				}

				int noOfWords = (str.charAt(0) - 'a') * 26
						+ (str.charAt(1) - 'a');

				str = str.substring(2);

				String words = str.substring(noOfWords);
				// System.out.println(words);

				int index = 0;

				String ans = "";

				for (int no = 0; no < noOfWords; no++)
				{
					int length = str.charAt(no) - 'a';
					ans += words.substring(index, index + length) + " ";
					index += length;
				}
				ans = ans.trim();

				System.out.println(ans);

				// System.out.println(str);
			}
			else
			{
				char first = (char) (len / 26 + 'a');
				char second = (char) (len % 26 + 'a');
				String ans = first + "" + second;
				// System.out.println(first+""+second);
				while (st.hasMoreTokens())
				{
					ans += (char) (st.nextToken().length() + 'a') + "";
				}
				st = new StringTokenizer(str);
				while (st.hasMoreTokens())
				{
					ans += st.nextToken();
				}
				for (int i = 0; i < ans.length(); i++)
				{
					int total = num;
					for (int j = i + 1; j < ans.length(); j++)
					{
						total += (ans.charAt(j) - 'a');
					}
					total %= 26;

					char newCh = (char) (ans.charAt(i) + total);
					if (newCh > 'z')
					{
						newCh -= 26;
					}
					ans = ans.substring(0, i) + newCh
							+ ans.substring(i + 1, ans.length());
				}

				System.out.println(ans);
			}
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
