import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseListenerEx extends JFrame{
	
	JLabel la = new JLabel("Hello");
	
	public MouseListenerEx() {
		
		setTitle("Mouse Event Example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.addMouseListener(new MyMouseListener());
		
		c.setLayout(null);
		la.setSize(50, 20);
		la.setLocation(30, 30);
		c.add(la);
		
		setSize(200, 200);
		setVisible(true);
		
	}
	
	// ���콺 ����͸� ���� �ʿ��� �͸� ����ϱ�
	class MyMouseListener extends MouseAdapter {
		@Override
		// �̷��� pressed �ϳ��� ��밡��
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			int x = e.getX();
			int y = e.getY();
			la.setLocation(x,y);
			super.mousePressed(e);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MouseListenerEx();

	}

}
