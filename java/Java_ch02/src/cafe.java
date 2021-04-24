import java.util.Scanner;

public class cafe {

	public static void main(String[] args) {
		
		System.out.println("커피 주문하세요");
		
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		String coffee;
		coffee = scanner.next();
		int count = scanner.nextInt();
		int price = 0;
		
		switch(coffee) {
			case "에스프레소" :
				price = 2000 * count;
				break;
			case "아메리카노" :
				price = 2500 * count;
				break;
			case "카푸치노" :
				price = 3000 * count;
				break;
			case "카페라떼" :
				price = 3500 * count;
				break;
			default :
				System.out.println("아무것도 주문하지 않으셨습니다.");
		}
		
		System.out.println(price + "원입니다.");	
	}

}
