
public class Hello 
//public �� ���ѻ�����. public �� �ƹ��� ��� �� �ִ� class
{
	public static int sum(int n, int m)
	{
		return n+m;
	}
	public static void main(String[] args)
	{   // ���� ���ڴ� args �ε� �������� string
		// �ڹٴ� �޸� �ڵ����� ����. static ���̸� ������ �� �޸𸮴� �Ҵ��ϰ� ������
		// TODO Auto-generated method stub
		int i = 20;
		int s;
		char a;
		
		s = sum(i, 10);  // s �� 30
		a = '?';
		System.out.println(a);       // ?
		System.out.println("Hello"); // Hello
		System.out.println(s);       // 30
	}

}
