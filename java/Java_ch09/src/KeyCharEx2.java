import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyCharEx2 extends JFrame {
	
	JLabel la = new JLabel("r=red y=yellow b=blue");
	
	public KeyCharEx2() {
		super("Ű���� �̺�Ʈ ���� ���� ����1");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);
		c.addKeyListener(new MyKeyListener());
		
		c.setFocusable(true);
		c.requestFocus();
		
		setSize(250, 150);
		setVisible(true);			
	}
	
	class MyKeyListener extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub

			switch (e.getKeyChar()) {
			case 'r':
				la.setText("�������Դϴ�");				
				getContentPane().setBackground(Color.RED);
				break;
			case 'b':
				la.setText("�Ķ����Դϴ�");				
				getContentPane().setBackground(Color.BLUE);
				break;
			case 'y':
				la.setText("������Դϴ�");				
				getContentPane().setBackground(Color.YELLOW);
				break;
			case 'q':
				System.exit(0); 
			default:
				break;
			}
			
			super.keyPressed(e);
		}
	}
		
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new KeyCharEx2();
	}
}
