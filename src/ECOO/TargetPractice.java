package ECOO;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TargetPractice
{

	public static void main(String[] args) throws Exception
	{
		for (int t = 0; t < 10; t++)
		{
			try
			{
				String[] values = br.readLine().split(" ");

				double gridWidth = Integer.parseInt(values[0]);
				double gridHeight = Integer.parseInt(values[1]);
				double ballX = Integer.parseInt(values[2]);
				double ballY = Integer.parseInt(values[3]);
				double hSpeed = Integer.parseInt(values[4]);
				double vSpeed = Integer.parseInt(values[5]);
				double originalVSpeed = vSpeed;

				String answer = "";

				for (int no = 0; no < 5; no++)
				{
					vSpeed = originalVSpeed;
					String[] values2 = br.readLine().split(" ");
					double targetH = Integer.parseInt(values2[0]);
					double targetX = Integer.parseInt(values2[1]);
					double targetY = Integer.parseInt(values2[2]);

					if (hSpeed == 0)
					{
						answer += "M";
						continue;
					}
					else if (vSpeed == 0)
					{
						if (ballY <= targetY && ballY >= targetY - targetH)
						{
							answer += "H";
						}
						else
						{
							answer += "M";
						}
						continue;
					}

					boolean done = false;

					double startX = ballX;
					double startY = ballY;

					while (!done)
					{
						double b = startY - (1.0 * vSpeed / hSpeed) * startX;
						double hitY = (1.0 * vSpeed / hSpeed) * targetX + b;

						if (hitY <= targetY && hitY >= targetY - targetH)
						{
							answer += "H";
							done = true;
							break;
						}
						else
						{
							if (vSpeed > 0)
							{
								startX += Math
										.abs(((hSpeed / vSpeed) * 1.0 * (1.0 * gridHeight - startY)));
								startY = gridHeight;

								if (startX >= gridWidth - 1)
								{
									answer += "M";
									done = true;
									break;
								}
								vSpeed = -vSpeed;
							}
							else if (vSpeed < 0)
							{
								startX += Math
										.abs(((hSpeed / (-vSpeed) * 1.0) * (1.0 * startY)));
								startY = 0;

								if (startX >= gridWidth - 1)
								{
									answer += "M";
									done = true;
									break;
								}
								vSpeed = -vSpeed;
							}
						}
					}

				}

				System.out.println(answer);
			}
			catch (Exception e)
			{
				System.out.println("HHHMM");
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
