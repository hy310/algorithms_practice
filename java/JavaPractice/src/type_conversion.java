
public class type_conversion {

	//type 강제변환, 자동변환
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		byte b = 127;
		int i = 100;
		
		System.out.println(b+i);   // 227. b 가 int형으로 자동전환
		System.out.println(10/4);  // 2
		System.out.println(10.0/4);  // 2.5   4 가 4.0으로 자동변환
		System.out.println((char)0x12340041);   // A (강제전환해서) 문자로 대문자 A. 
		System.out.println((byte)(b+i));   // 227을 byte 형 크기만큼 자름 : -29
		System.out.println((int)2.9 + 1.8);  // 3.8   2.9만 강제전환
		System.out.println((int)(2.9+1.8));   //4    4.7이 강제전환
		System.out.println((int)2.9+(int)1.8);	//3	
	}

}
