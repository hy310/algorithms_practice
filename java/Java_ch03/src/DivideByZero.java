import java.util.Scanner;

public class DivideByZero {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("�������� �Է��Ͻÿ�:");
		int dividend; //������
		int divisor;  //������
		dividend = scanner.nextInt();
		System.out.println("�������� �Է��Ͻÿ�:");
		divisor = scanner.nextInt();
		
		try {
		System.out.println(dividend+"�� "+divisor+"�� ������ ���� " +dividend/divisor + "�Դϴ�.");
		}
		catch(ArithmeticException e) {
			System.out.println("0���� ���� �� �����ϴ�.");
		}
		finally
		{
			scanner.close();
		}
	}

}
