import java.util.Scanner;

public class WhileSample {

	public static void main(String[] args) {
		System.out.println("정수를 입력하고 마지막에 0을 입력하세요.");
		Scanner scanner = new Scanner(System.in);
		
		int count = 0, n = 0;
		double sum = 0;
		
		while((n = scanner.nextInt())!=0)
		{
			sum = sum + n;
			count++;
		}
		
		System.out.println("수의 개수는 " + count + "개이며 평균은 " +
		sum/count + "입니다.");
		
		scanner.close();
	}
}
