import java.util.Scanner;

public class ScannerEX {
	
	public static void main(String[] args) {
		
		System.out.println("�̸�, ����, ����, ü��, ���ſ��θ� �и��Ͽ� �Է��ϼ���");
		
		Scanner scanner;
		// int x;
		scanner = new Scanner(System.in);
		// x =10;
		
		String name;
		name = scanner.next();
		
		System.out.println("����� �̸��� " + name + "�Դϴ�");
		
		String city = scanner.next();
		System.out.println("����� ��� ���ô� " + city + "�Դϴ�");
		
		int age = scanner.nextInt();
		System.out.println("����� ���̴� " + age + "�� �Դϴ�");
		
		double weight = scanner.nextDouble();
		System.out.println("����� ü���� " + weight + "kg �Դϴ�");
		
		boolean single = scanner.nextBoolean();
		System.out.println("����� ���ſ��δ� " + single + "�Դϴ�");
		
		scanner.close();
		
	}

}
