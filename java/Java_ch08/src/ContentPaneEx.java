import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class ContentPaneEx extends JFrame {
	
	public ContentPaneEx() {     // ������
		setTitle("3 buttons example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// â�� ������ (����) �� ����. â�����鼭 ���α׷��� ������Ѷ�
		
		// �ٴ��� ������ ����� �����
		Container contentPane = getContentPane();
		contentPane.setBackground(Color.ORANGE);
		
		//��ġ������
		contentPane.setLayout(new FlowLayout()); // �Ϸķ�
		
		// ��ư �����
		// ��ư�� �ᱹ contentPane ���� �ִ� ����
		// Jbutton �� �ܺ� Ŭ������ �����ؼ� ����� ����
		// �׷����� ~~~ = new ~~ �̷������� �ؾ��ϴµ� �Ʊ�ó�� ����ؼ� ����ص� ��
		contentPane.add(new JButton("OK"));
		contentPane.add(new JButton("Cancel"));
		contentPane.add(new JButton("Ignore"));
		
		setSize(300, 150);
		setVisible(true);
	}
	
	public static void main(String[] args) {
		//ContentPaneEx content = new ContentPaneEx();
		// ���� �� ����� �� ����. ������ content ��� �̸� ���� ����
		
		new ContentPaneEx();
		
	}

}
