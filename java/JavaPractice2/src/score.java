import java.util.ArrayList;
import java.util.Scanner;

public class score {

	public static void main(String[] args) {
		Scanner scanner;
		scanner = new Scanner(System.in);
		
		System.out.print("빈 칸으로 분리하여 5 개의 학점을 입력(A/B/C/D/F)>>");
		ArrayList<String> a = new ArrayList<String>();
		for(int i=0; i<5; i++)
		{
			String s = scanner.next();
			a.add(s);
		}
		
		for(int i=0; i<a.size(); i++)
		{
			String name = a.get(i);
			if (name.equals("A"))
				System.out.print("4.0 ");
			else if (name.equals("B"))
				System.out.print("3.0 ");
			else if (name.equals("C"))
				System.out.print("2.0 ");
			else if (name.equals("D"))
				System.out.print("1.0 ");
			else if (name.equals("F"))
				System.out.print("0.0 ");
			else
				System.out.println("A,B,C,D,F 중 하나를 입력하세요.");
		}
		
		scanner.close();	

	}

}
