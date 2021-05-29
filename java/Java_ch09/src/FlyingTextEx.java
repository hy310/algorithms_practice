import java.awt.Container;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class FlyingTextEx extends JFrame{
	
	JLabel la = new JLabel("HELLO");
	
	public FlyingTextEx() {
		super("상,하,좌,우 키를 이용하여 텍스트 움직이기");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);   // 움직일 것이니까 고정하지 말기
		la.setSize(50, 50);
		la.setLocation(100, 20);
		c.add(la);
		c.addKeyListener(new MyKeyListener());
		
		c.setFocusable(true);
		c.requestFocus();
		
		setSize(200, 200);
		setVisible(true);		
		
	}
	
	class MyKeyListener extends KeyAdapter{
		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
			
			// 상하좌우키가 유니코드키가 아니기 때문에 keyCode 를 통해서 받아주기
			int keyCode = e.getKeyCode();
			switch (keyCode) {
			case KeyEvent.VK_UP:
				la.setLocation(la.getX(), la.getY() - 10);
				break;
			case KeyEvent.VK_DOWN:
				la.setLocation(la.getX(), la.getY() + 10);
				break;
			case KeyEvent.VK_LEFT:
				la.setLocation(la.getX() - 10, la.getY());
				break;
			case KeyEvent.VK_RIGHT:
				la.setLocation(la.getX() + 10, la.getY());
				break;
			// 상하좌우키가 명확하기 때문에 default 안넣어도되지만 넣어도 됨.	
			default:
				break;
			}
			super.keyPressed(e);
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new FlyingTextEx();

	}

}
