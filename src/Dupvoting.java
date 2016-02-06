import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Dupvoting
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int p = Integer.parseInt(br.readLine());
		int u = Integer.parseInt(br.readLine());

		int r1 = Integer.parseInt(br.readLine());
		int r2 = Integer.parseInt(br.readLine());

		int total = 0;

		// Brute force loop that counts all possibilties
		for (int dup = 0; dup <= u; dup++)
			for (int up = 0; up <= u - dup; up++)
			{
				int down = u - dup - up;
					if (dup * 2 + up - down == p &&
							(r1 * 1.0 / r2 == dup * 1.0 / up
									|| r1 * 1.0 / r2 == up * 1.0 / dup ||
									r1 * 1.0 / r2 == dup * 1.0 / down
									|| r1 * 1.0 / r2 == down * 1.0 / dup ||
									r1 * 1.0 / r2 == up * 1.0 / down
									|| r1 * 1.0 / r2 == down * 1.0 / up))
						total++;
			}

		System.out.println(total);

	}

}
