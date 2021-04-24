import java.util.Scanner;

public class floor {

	public static void main(String[] args) {
		
		System.out.println("몇 층인지 입력하세요");

		Scanner scanner;
		
		scanner = new Scanner(System.in);
		
		int floor = scanner.nextInt();
		int height = floor * 5;
		System.out.println(height + "m 입니다.");
		
	}
}
