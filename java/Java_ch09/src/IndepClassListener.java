import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class IndepClassListener extends JFrame {
	
	public IndepClassListener() {
		setTitle("Action �̺�Ʈ ������ ����");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		
		c.setLayout(new FlowLayout());
		JButton btn = new JButton("Action");    // ��ư �����
		// ��ư�� �׼� ������
		// ��ư�� ������ �츮�� ���� �׼Ǹ����� �̸� MyListener �� ���Բ�
		btn.addActionListener(new MyListener());
		c.add(btn);    // ��ư ���� �� �ٿ��ֱ�
		
		setSize(250, 120);
		setVisible(true);
		
	}

	public static void main(String[] args) {
		new IndepClassListener();
	}

}

// ������ Ŭ������ �̺�Ʈ ������ �ۼ�
// ��ư ������ �� �۵��ǰ� ���� ����
class MyListener implements ActionListener{
	public void actionPerformed(ActionEvent e) {
		// ActionListener �߻�Ŭ������ ���� �޼��� �Ʒ��� �ۼ�
		JButton b = (JButton)e.getSource();  // �̺�Ʈ�� ����� �ҽ� �޾ƿ�
		// ��� ���� �̺�Ʈ�� ��ȿ�ϴٸ�
		if(b.getText().equals("Action"))   
			// �̺�Ʈ�� �޾ƿԴ��� "�׼�" �̶�� �۾��� �Ȱ��� = �� ��ȿ�� �̺�Ʈ�̴�
			b.setText("�׼�");    // �ؽ�Ʈ�� �ѱ۷� �ٲ��
		else
			b.setText("Action");
	}
}