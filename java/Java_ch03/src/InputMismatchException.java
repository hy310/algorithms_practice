import java.util.Scanner;

public class InputMismatchException {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num = 0;
		int sum = 0;
		
		System.out.println("정수 3개를 입력하세요");
		for(int i=0; i<3; i++)
		{
			System.out.print(i+">>");
			
			try
			{
				num = scanner.nextInt();
			}
			catch (Exception e) 
			{
				System.out.println("정수가 아닙니다. 다시 입력하세요!");
				scanner.next();
				i--;
				continue;
			}
			
			sum = sum+num;
			}
			System.out.println("합은 "+sum);
			scanner.close();
		}
}
