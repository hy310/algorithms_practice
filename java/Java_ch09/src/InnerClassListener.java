import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class InnerClassListener extends JFrame{
	
	public InnerClassListener() {
		setTitle("���� Ŭ������ ���� �̺�Ʈ");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		JButton btn = new JButton("Action");
		btn.addActionListener(new MyActionListener());
		c.add(btn);    // ����Ʈ�� c�ǿ� ��� ���� ��ư ���̱�
		
		setSize(200, 120);
		setVisible(true);
		
		}

	// ���� �ƴ϶� �� �ȿ� ���ٰ� �ؼ� ���� Ŭ������
	class MyActionListener implements ActionListener{

		public void actionPerformed(ActionEvent e) {
			JButton b = (JButton)e.getSource();
			if(b.getText().equals("Action"))
				b.setText("�׼�");
			else
				b.setText("Action");
			
			// ��ư �̸� ������ title �̸��� �ٲٱ��
			InnerClassListener.this.setTitle(b.getText());
			
		}
	
	}
	
	public static void main(String[] args) {
		
		new InnerClassListener();

	}

}
