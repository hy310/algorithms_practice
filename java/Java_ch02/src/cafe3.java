import java.util.Scanner;

public class cafe3 {

	public static void main(String[] args) {
		
		System.out.println("Ŀ�� �ֹ��ϼ���");
		
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		String coffee;
		coffee = scanner.next();
		int count = scanner.nextInt();
		double price = 0;
		
		if(coffee.equals("����������"))
			if (count >= 10)
				price = (2000 * count) * 0.95;
			else
				price = 2000 * count;
		else if (coffee.equals("�Ƹ޸�ī��"))
			price = 2500 * count;
		else if (coffee.equals("īǪġ��"))
			price = 3000 * count;
		else if (coffee.equals("ī���"))
			price = 3500 * count;
		else 
			System.out.println("�޴��� �ٽ� �ֹ����ּ���");
				
		System.out.println((int)price + "���Դϴ�.");	
	}

}
