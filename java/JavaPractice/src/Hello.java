
public class Hello 
//public 은 권한생성자. public 은 아무나 열어볼 수 있는 class
{
	public static int sum(int n, int m)
	{
		return n+m;
	}
	public static void main(String[] args)
	{   // 들어가는 인자는 args 인데 문자형인 string
		// 자바는 메모리 자동으로 구성. static 붙이면 무조건 이 메모리는 할당하게 강제함
		// TODO Auto-generated method stub
		int i = 20;
		int s;
		char a;
		
		s = sum(i, 10);  // s 는 30
		a = '?';
		System.out.println(a);       // ?
		System.out.println("Hello"); // Hello
		System.out.println(s);       // 30
	}

}
