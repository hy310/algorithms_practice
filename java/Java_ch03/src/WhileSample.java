import java.util.Scanner;

public class WhileSample {

	public static void main(String[] args) {
		System.out.println("������ �Է��ϰ� �������� 0�� �Է��ϼ���.");
		Scanner scanner = new Scanner(System.in);
		
		int count = 0, n = 0;
		double sum = 0;
		
		while((n = scanner.nextInt())!=0)
		{
			sum = sum + n;
			count++;
		}
		
		System.out.println("���� ������ " + count + "���̸� ����� " +
		sum/count + "�Դϴ�.");
		
		scanner.close();
	}
}
