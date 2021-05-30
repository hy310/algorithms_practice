import java.util.Scanner;
import java.util.StringTokenizer;

public class sumcalculator {

	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		String addex = scanner.nextLine();
		StringTokenizer st = new StringTokenizer(addex, "+");
		
		int sum = 0;
		while(st.hasMoreTokens()) {
			String token = st.nextToken();
			token = token.trim();
			sum += Integer.parseInt(token);
		}
		
		System.out.println("гую╨ " + sum);
		scanner.close();
	}
}
