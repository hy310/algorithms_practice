
public class type_conversion {

	//type ������ȯ, �ڵ���ȯ
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte b = 127;
		int i = 100;
		
		System.out.println(b+i);   // 227. b �� int ������ �ڵ���ȯ
		System.out.println(10/4);  // 2
		System.out.println(10.0/4);  // 2.5   4 �� 4.0���� �ڵ���ȯ
		System.out.println((char)0x12340041);   // A (������ȯ�ؼ�) ���ڷ� �빮�� A. 
		System.out.println((byte)(b+i));   // 227�� byte �� ũ�⸸ŭ �ڸ� : -29
		System.out.println((int)2.9 + 1.8);  // 3.8   2.9�� ������ȯ
		System.out.println((int)(2.9+1.8));   //4    4.7�� ������ȯ
		System.out.println((int)2.9+(int)1.8);	//3	
	}

}
