import java.util.Scanner;
public class BreakExample {

	public static void main(String[] args) {
		System.out.println("exit�� �Է��ϸ� �����մϴ�.");
		
		Scanner scanner = new Scanner(System.in);
		while(true)
		{
			System.out.println(">>");
			String text = scanner.next();
			if (text.equals("exit"))
				break;
		}
		System.out.println("�����մϴ�...");
		scanner.close();
	}
}
