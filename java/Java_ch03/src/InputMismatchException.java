import java.util.Scanner;

public class InputMismatchException {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num = 0;
		int sum = 0;
		
		System.out.println("���� 3���� �Է��ϼ���");
		for(int i=0; i<3; i++)
		{
			System.out.print(i+">>");
			
			try
			{
				num = scanner.nextInt();
			}
			catch (Exception e) 
			{
				System.out.println("������ �ƴմϴ�. �ٽ� �Է��ϼ���!");
				scanner.next();
				i--;
				continue;
			}
			
			sum = sum+num;
			}
			System.out.println("���� "+sum);
			scanner.close();
		}
}
