import java.awt.Container;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class FlyingTextEx extends JFrame{
	
	JLabel la = new JLabel("HELLO");
	
	public FlyingTextEx() {
		super("��,��,��,�� Ű�� �̿��Ͽ� �ؽ�Ʈ �����̱�");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container c = getContentPane();
		c.setLayout(null);   // ������ ���̴ϱ� �������� ����
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
			
			// �����¿�Ű�� �����ڵ�Ű�� �ƴϱ� ������ keyCode �� ���ؼ� �޾��ֱ�
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
			// �����¿�Ű�� ��Ȯ�ϱ� ������ default �ȳ־������ �־ ��.	
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
