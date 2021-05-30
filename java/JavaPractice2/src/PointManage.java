import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;

public class PointManage {

	public static void main(String[] args) {
		HashMap<String, Integer> dic = new HashMap<String, Integer>();
		Scanner scanner;
		scanner = new Scanner(System.in);
		System.out.println("** 포인트 관리 프로그램입니다 **");
		
		while(true)
		{
			System.out.print("이름과 포인트 입력>>");
			String a = scanner.next();
			if(a.equals("exit")) {
				System.out.println("프로그램을 종료합니다...");
				break;
			}
			else if(dic.get(a) != null)
			{
				int b = scanner.nextInt();
				b = b + dic.get(a);
				dic.put(a,  b);
			}
			else {
				int b = scanner.nextInt();
				dic.put(a,  b);
			}
			Set<String> keys = dic.keySet();
			Iterator<String> it = keys.iterator();
			while(it.hasNext()) {
				String key = it.next();
				int value = dic.get(key);
				System.out.print("(" + key + "," + value + ")");
			}
			System.out.print("\n");
		}
		scanner.close();
	}

}
