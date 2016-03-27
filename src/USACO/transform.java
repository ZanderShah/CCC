package USACO;
/*
ID: zander.1
LANG: JAVA
TASK: transform
 */
import java.io.*;
import java.util.*;

class transform
{
	public static int[][] rotate(int[][] array)
	{
		int[][] rotation = new int[array.length][array.length];
		
		for (int i = 0; i < rotation.length; i++)
			for (int j = 0; j < rotation.length; j++)
				rotation[i][j] = array[j][array.length - 1 -i];

		return rotation;
	}

	public static int[][] reflect(int[][] array)
	{
		int[][] reflection = new int[array.length][array.length];

		for (int i = 0; i < reflection.length; i++)
			for (int j = 0; j < reflection.length; j++)
				reflection[i][j] = array[i][array.length - 1 - j];
		
		return reflection;
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader f = new BufferedReader(new FileReader("transform.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"transform.out")));

		int size = Integer.parseInt(f.readLine());
		int[][] before = new int[size][size];
		int[][] after = new int[size][size];

		for (int h = 0; h < size; h++)
		{
			String st = f.readLine();

			for (int w = 0; w < size; w++)
				before[h][w] = st.charAt(w);
		}

		for (int h = 0; h < size; h++)
		{
			String st = f.readLine();

			for (int w = 0; w < size; w++)
				after[h][w] = st.charAt(w);
		}

		if (Arrays.deepEquals(rotate(before), after))
			out.println(1);
		else if (Arrays.deepEquals(rotate(rotate(before)), after))
			out.println(2);
		else if (Arrays.deepEquals(rotate(rotate(rotate(before))), after))
			out.println(3);
		else if (Arrays.deepEquals(reflect(before), after))
			out.println(4);
		else if (Arrays.deepEquals(rotate(reflect(before)), after)
				|| Arrays.deepEquals(rotate(rotate(reflect(before))), after)
				|| Arrays.deepEquals(rotate(rotate(rotate(reflect(before)))), after))
		{
			out.println(5);
		}
		else if (Arrays.deepEquals(before, after))
			out.println(6);
		else
			out.println(7);

		out.close();
		System.exit(0);
	}
}
