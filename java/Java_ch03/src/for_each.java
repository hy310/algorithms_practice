
public class for_each {

	public static void main(String[] args) {
		int [] n = { 1, 2, 3, 4, 5 };
		int sum = 0;
		
		for(int k : n)      // k�� n[0], n[1], n[2], ... n[4] �� �ݺ�
		{
			System.out.print(k + " ");    // �ݺ��Ǵ� k �� ���
			sum += k;
		}
		System.out.println("���� " + sum);
		
		String f[] = {"���", "��", "�ٳ���", "ü��", "����", "����" };
		for(String s : f) 
			System.out.print(s + " ");
	}

}
