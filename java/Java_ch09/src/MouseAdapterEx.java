import java.awt.Container;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseAdapterEx extends JFrame{
	
	JLabel la = new JLabel("Hello");
	
	public MouseAdapterEx() {
		
		setTitle("Mouse Event Example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.addMouseListener(new MyMouseAdapter());
		
		c.setLayout(null);
		la.setSize(50, 20);
		la.setLocation(30, 30);
		c.add(la);
		
		setSize(200, 200);
		setVisible(true);
		
	}
	
	// 마우스 어댑터를 통해 필요한 것만 사용하기
	class MyMouseAdapter extends MouseAdapter {
		@Override
		// 이렇게 pressed 하나만 사용가능
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
