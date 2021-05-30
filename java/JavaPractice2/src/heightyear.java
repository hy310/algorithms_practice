import java.util.Scanner;
import java.util.Vector;

public class heightyear {

	public static void main(String[] args) {
		Vector<Integer> v = new Vector<Integer>();
		System.out.print("2000~2009년까지 1년 단위로 키(cm)를 입력\n>>");
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		for(int i=0; i<10; i++)
		{
			v.add(scanner.nextInt());
		}
		
		int max = 0;
		int max_index = 0;
		
		for(int i=0; i<9; i++)
		{
			if(max < v.get(i+1) - v.get(i)) {
				max = v.get(i+1) - v.get(i);
				max_index = i;
			}
			else
				continue;
		}
		System.out.print("가장 키가 많이 자란 년도는 " + (int)(2000 + max_index) + "년 " + (float)max + "cm");
		scanner.close();
	}
}
