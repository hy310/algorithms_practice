
public class Circle02 {
	int radius;
	String name;
	
	public Circle02()
	{
		radius = 1; name = "";     // radius �� �ʱⰪ�� 1
	}
	
	public Circle02(int r, String n) {
		radius = r; name = n;
	}
	
	public double getArea() {
		return 3.14 * radius * radius;
	}
	
	public static void main(String[] args) {
		Circle02 pizza = new Circle02(10, "���ִ� ����");    // circle ��ü ����, ������ 10
		double area = pizza.getArea();
		System.out.println(pizza.name + "�� ������ " + area);
		
		Circle02 donut = new Circle02();         // circle ��ü ����, ������ 1
		donut.name = "���ִ� ����";
		area = donut.getArea();
		System.out.println(donut.name + "�� ������ " + area);

	}

}
