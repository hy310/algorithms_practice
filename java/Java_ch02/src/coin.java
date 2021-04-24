import java.util.Scanner;

public class coin {

	public static void main(String[] args) {
		
		System.out.println("돈의 액수를 입력하세요");
		
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
		
		
		
		System.out.println("오만원" + fiftythousand + "개, 만원" 
		+ tenthousand + "개, 천원" + thousand + "개, 500원"
		+ fivehundred + "개, 100원" + hundred + "개, 10원" 
		+ ten + "개, 1원" + one + "개");
		
	}

}
