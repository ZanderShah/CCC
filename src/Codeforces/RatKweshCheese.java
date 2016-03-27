package Codeforces;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RatKweshCheese
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		double x = Double.parseDouble(st.nextToken());
		double y = Double.parseDouble(st.nextToken());
		double z = Double.parseDouble(st.nextToken());
		
		double[] v = new double[9];
		
		String[] ans = {"x^y^z", "x^z^y", "(x^y)^z", "y^x^z", "y^z^x", "(y^x)^z", "z^x^y", "z^y^x", "(z^x)^y"};
		
		v[0] =  z * Math.log(y) + Math.log(Math.log(x));
		v[1] = y * Math.log(z) + Math.log(Math.log(x));
		v[2] = Math.log(y * z * Math.log(x));
		
		v[3] =  z * Math.log(x) + Math.log(Math.log(y));
		v[4] = x * Math.log(z) + Math.log(Math.log(y));
		v[5] = Math.log(x * z * Math.log(y));
		
		v[6] =  y * Math.log(x) + Math.log(Math.log(z));
		v[7] = x * Math.log(y) + Math.log(Math.log(z));
		v[8] = Math.log(x * y * Math.log(z));
		
		int max = 0;
		
		for (int i = 1; i < 9; i++)
			if (v[i] > v[max])
				max = i;
		
		System.out.println(ans[max]);
	}

}
