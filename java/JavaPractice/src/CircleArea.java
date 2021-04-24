
public class CircleArea {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		final double PI = 3.14; // final 사용하여 상수 만들기. 원주율
		double radius = 10.2;   // 원의 반지름
		double circleArea = radius * radius * PI;   // 원의 면적 계산식
		
		// 원의 면적 화면에 출력
		System.out.print("반지름 " + radius + " , ");
		System.out.println("원의 면적 = " + circleArea);
		
		// 반지름 10.2 , 원의 면적 = 326.xx
	}

}
