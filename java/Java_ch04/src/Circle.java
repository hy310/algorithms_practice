
public class Circle {
	int radius;
	String name;
	
	public double getArea() 
	{
		return 3.14 * radius * radius; 
	}


	public static void main(String[] args) {
		Circle pizza;
		pizza = new Circle();
		pizza.radius = 10;
		pizza.name = "맛있는 피자";
		double area = pizza.getArea();
		System.out.println(pizza.name + "의 면적은 " + area);
		
		Circle donut = new Circle();
		donut.radius = 2;
		donut.name = "맛있는 도넛";
		area = donut.getArea();
		System.out.println(donut.name + "의 면적은 " + area);
	}
}

