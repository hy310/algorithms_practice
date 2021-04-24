
public class BitShiftOperator {
	public static void main(String[] args) {
		
		short a = (short)0x55ff;
		short b = (short)0x00ff;
		//비트연산
		System.out.println("[비트 연산 결과]");
		// printf 는 값을 4자리의 16진수로 출력하고 빈 값에 0을 삽입
		System.out.printf("%04x\n", (short)(a&b));
		System.out.printf("%04x\n", (short)(a|b));
		System.out.printf("%04x\n", (short)(a^b));
		System.out.printf("%04x\n", (short)(~a));
		
		byte c = 20;  //0x14
		byte d = -8;  //0xf8
		
		System.out.println("[시프트 연산 결과]");
		System.out.println(c<<2);
		System.out.println(c>>2);
		System.out.println(d>>2);
		System.out.printf("%x\n", (d>>>2));
		
	}

}
