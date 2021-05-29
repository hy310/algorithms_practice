import java.awt.Container;
import java.awt.FlowLayout;
import javax.swing.JButton;
import javax.swing.JFrame;

public class FlowLayoutEx extends JFrame{

	public FlowLayoutEx() {
		setTitle("first flow layout");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		// ����Ʈ�� �˾Ƴ���
		Container contentPane = getContentPane();
		
		// ���� ����, ���� 30, ���� 40 FlowLayout
		contentPane.setLayout(new FlowLayout(FlowLayout.LEFT, 30, 40));
		
		contentPane.add(new JButton("add"));
		contentPane.add(new JButton("sub"));
		contentPane.add(new JButton("mul"));
		contentPane.add(new JButton("div"));
		contentPane.add(new JButton("Calculate"));
		
		setSize(300, 200);   // ������ ũ�� 300 * 200 ����
		setVisible(true);    // ȭ�鿡 ������ ���
	}
	public static void main(String[] args) {
		new FlowLayoutEx();
	}

}
