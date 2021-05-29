import java.awt.Container;
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
	
	class MyMouseListener implements MouseListener{

		@Override
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			//���콺 ��ǥ ���� ���
			int x = e.getX();   // ���콺 Ŭ����ǥ x
			int y = e.getY();   // ���콺 Ŭ����ǥ y
			la.setLocation(x, y);    // (x,y) ��ġ�� ���̺� �̵�
					
		}

		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MouseListenerEx();

	}

}
