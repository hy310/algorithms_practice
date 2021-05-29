import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class KeyCharEx extends JFrame {
	
	JLabel la = new JLabel("<Enter> Ű�� ������ �ٲ�ϴ�.");
	
	public KeyCharEx() {
		super("Keyboard Event Example");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Container c = getContentPane();
		c.setLayout(new FlowLayout());
		c.add(la);
		c.addKeyListener(new MyKeyListener());
		
		// keyboard �̿��ϱ� ������ focus ����ֱ�
		// 'c �� focus ��' ��� ���־����
		c.setFocusable(true);    // ����Ʈ���� ��Ŀ���� ���� �� �ֵ��� ����
		c.requestFocus();        // ����Ʈ�ҿ� ��Ŀ�� ����
		
		setSize(250, 150);
		setVisible(true);			
	}
	
	class MyKeyListener extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			// TODO Auto-generated method stub
			// ���� ǥ���� r,g,b ����
			// math ����ϸ� �Ҽ��� ������ int ��. color �� 0~255 ����
			int r = (int)(Math.random()*256);     // Math ����ؼ� ������ �ޱ�
			int g = (int)(Math.random()*256);
			int b = (int)(Math.random()*256);
			
			switch (e.getKeyChar()) {
			case '\n':
				la.setText("r = " + r + ", g = " + g + ", b = " + b);				
				getContentPane().setBackground(new Color(r, g, b));
				
				break;
			case 'q':
				System.exit(0);    // �ý��� ���� ����
			}
			
			super.keyPressed(e);
		}
		
	}
		

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new KeyCharEx();
	}

}
