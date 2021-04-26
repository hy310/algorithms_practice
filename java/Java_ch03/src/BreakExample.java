import java.util.Scanner;
public class BreakExample {

	public static void main(String[] args) {
		System.out.println("exit을 입력하면 종료합니다.");
		
		Scanner scanner = new Scanner(System.in);
		while(true)
		{
			System.out.println(">>");
			String text = scanner.next();
			if (text.equals("exit"))
				break;
		}
		System.out.println("종료합니다...");
		scanner.close();
	}
}
