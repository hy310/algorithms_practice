
public class Circle02 {
	int radius;
	String name;
	
	public Circle02()
	{
		radius = 1; name = "";     // radius 의 초기값은 1
	}
	
	public Circle02(int r, String n) {
		radius = r; name = n;
	}
	
	public double getArea() {
		return 3.14 * radius * radius;
	}
	
	public static void main(String[] args) {
		Circle02 pizza = new Circle02(10, "맛있는 피자");    // circle 객체 생성, 반지름 10
		double area = pizza.getArea();
		System.out.println(pizza.name + "의 면적은 " + area);
		
		Circle02 donut = new Circle02();         // circle 객체 생성, 반지름 1
		donut.name = "맛있는 도넛";
		area = donut.getArea();
		System.out.println(donut.name + "의 면적은 " + area);

	}

}
