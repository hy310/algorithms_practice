import java.util.Scanner;

public class coin {

	public static void main(String[] args) {
		
		System.out.println("���� �׼��� �Է��ϼ���");
		
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		int money = scanner.nextInt();
		int fiftythousand = money / 50000;
		money = money - fiftythousand * 50000;
		int tenthousand = money / 10000;
		money = money - tenthousand * 10000;
		int thousand = money / 1000;
		money = money - thousand * 1000;
		int fivehundred = money / 500;
		money = money - fivehundred * 500;
		int hundred = money / 100;
		money = money - hundred * 100;
		int ten = money / 10;
		money = money - ten * 10;
		int one = money / 1;
		
		
		
		System.out.println("������" + fiftythousand + "��, ����" 
		+ tenthousand + "��, õ��" + thousand + "��, 500��"
		+ fivehundred + "��, 100��" + hundred + "��, 10��" 
		+ ten + "��, 1��" + one + "��");
		
	}

}
