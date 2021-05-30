
public class samenumprint {

	public static void main(String[] args) {
		int a, b, c;
		while(true)
		{
			a = (int)(Math.random() * 3 + 1);
			b = (int)(Math.random() * 3 + 1);
			c = (int)(Math.random() * 3 + 1);
			
			System.out.println(a + " " + b + " " + c);
			
			if ((a == b) && (b == c)) {
				System.out.println("¼º°ø");
				break; }
			
			else
				continue;
		}
	}
}