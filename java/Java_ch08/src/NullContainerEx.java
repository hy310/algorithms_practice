import java.awt.Container;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class NullContainerEx extends JFrame{
	
	public NullContainerEx() {
		setTitle("��ġ������ ���� ���� ��ġ�� ��ġ�ϴ� ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container contentPane = getContentPane();
		//����Ʈ���� ��ġ������ ����
		contentPane.setLayout(null);
		
		JLabel la = new JLabel("Hello, Press Buttons!");
		la.setLocation(130, 50);
		la.setSize(200, 20);
		contentPane.add(la);  // la �� ����Ʈ�ҿ� ����
		
		// 9���� ��ư ������Ʈ ����, ������ ũ�� ����, ��ġ�� ���� ��ġ��
		for(int i=1; i<=9; i++) {
			JButton b = new JButton(Integer.toString(i)); //��ư����
			b.setLocation(i*15, i*15);    // ��ư�� ��ġ ����
			b.setSize(50, 20);    // ��ư�� ũ��� �����ϰ�
			contentPane.add(b);
		}
		
		setSize(300, 200);
		setVisible(true);
	}

	public static void main(String[] args) {
		new NullContainerEx();
	}

}
