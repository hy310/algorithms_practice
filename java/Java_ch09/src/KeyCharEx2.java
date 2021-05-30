import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyCharEx2 extends JFrame {
	
	JLabel la = new JLabel("r=red y=yellow b=blue");
	
	public KeyCharEx2() {
		
		setTitle("Ű���� �̺�Ʈ ���� ���� ����1");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);

		c.addKeyListener(new MyKeyListener(this));
		// �̺�Ʈ ������ ����ϸ� ��ü �ּ� �Բ� ������
		
		c.setFocusable(true);
		c.requestFocus();
		
		setSize(250, 150);
		setVisible(true);			
	}
		
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new KeyCharEx2();
	}
}

class MyKeyListener extends KeyAdapter {
	
	KeyCharEx2 superClass;  //�θ� ��ü ���� ��
	
	@Override
	public void keyPressed(KeyEvent e) {
		// TODO Auto-generated method stub
		
		Component c = (Component)e.getSource();
		
		switch (e.getKeyChar()) {
		case 'r':
			superClass.la.setText("�������Դϴ�");
			c.setBackground(Color.RED);
			break;
		case 'b':
			superClass.la.setText("�Ķ����Դϴ�");				
			c.setBackground(Color.BLUE);
			break;
		case 'y':
			superClass.la.setText("������Դϴ�");				
			c.setBackground(Color.YELLOW);
			break;
		case 'q':
			System.exit(0); 
		default:
			break;
		}
		
		super.keyPressed(e);
	}
	
	MyKeyListener(KeyCharEx2 superClass)
	{
		this.superClass = superClass;    // ���ڷ� ���� �θ� ��ü �������� ����
	}
		
}

