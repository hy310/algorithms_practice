import java.util.Scanner;

public class cafe {

	public static void main(String[] args) {
		
		System.out.println("Ŀ�� �ֹ��ϼ���");
		
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		String coffee;
		coffee = scanner.next();
		int count = scanner.nextInt();
		int price = 0;
		
		switch(coffee) {
			case "����������" :
				price = 2000 * count;
				break;
			case "�Ƹ޸�ī��" :
				price = 2500 * count;
				break;
			case "īǪġ��" :
				price = 3000 * count;
				break;
			case "ī���" :
				price = 3500 * count;
				break;
			default :
				System.out.println("�ƹ��͵� �ֹ����� �����̽��ϴ�.");
		}
		
		System.out.println(price + "���Դϴ�.");	
	}

}
